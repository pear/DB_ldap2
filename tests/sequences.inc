<?php // -*- PHP -*-

function error_handler(&$obj) {
    print "sequences.inc error_handler\n";
}
ob_implicit_flush(true);
$dbh->setErrorHandling(PEAR_ERROR_PRINT, "%s <- good error catched\n");
$dbh->dropSequence("sequence");

// 1) test that sequences are not created if "ondemand" is false
$dbh->setErrorHandling(PEAR_ERROR_RETURN);
$e = $dbh->nextId("sequence", false);
if (DB::isError($e)) {
    print $e->getMessage() . "\n";
} else {
    print "test 1) failed!\n";
}
// 2) test that the sequence is not created but the error is
// handled by the class error handler
$dbh->setErrorHandling(PEAR_ERROR_PRINT, "%s <- good error catched\n");
$e = $dbh->nextId("sequence", false);
if (!DB::isError($e)) {
    print "test 2) failed!\n";
}
$dbh->_default_error_mode = null;

// 3) test that sequences are created if "ondemand" is true, and that
// two successive nextIds return adjacent values
$a = $dbh->nextId("sequence");
$b = $dbh->nextId("sequence");

if (DB::isError($a)) {
    print "a: ".$a->toString()."\n";
} else {
    print "a=$a\n";
}
if (DB::isError($b)) {
    print "b: ".$b->toString()."\n";
} else {
    print "b=$b\n";
}
print "b-a=".($b-$a)."\n";

// 4) test that the user-specified error handler is really disabled
// during nextId, with per-object handler as well as global handler
$dbh->dropSequence("sequence");
$dbh->setErrorHandling(PEAR_ERROR_CALLBACK, "error_handler");
$c = $dbh->nextId("sequence");
if (DB::isError($c)) {
    print "c: ".$c->toString()."\n";
} else {
    print "c=$c\n";
}
$dbh->dropSequence("sequence");
$dbh->_default_error_mode = null;
PEAR::setErrorHandling(PEAR_ERROR_CALLBACK, "error_handler");
$d = $dbh->nextId("sequence");
if (DB::isError($d)) {
    print "d: ".$d->toString()."\n";
} else {
    print "d=$d\n";
}

// 5) test that the sequence is handled right when the table is empty

// Backend with real sequences may don't like that
PEAR::pushErrorHandling(PEAR_ERROR_RETURN);
$dbh->query(array(array('dn'=>$dbh->getSequenceName("sequence"), 'action'=>'delete')));
PEAR::popErrorHandling();
$e = $dbh->nextID('sequence');
if (DB::isError($d)) {
    print "e: ".$d->toString()."\n";
} else {
    print "e=$d\n";
}

// final clean-up
$dbh->dropSequence("sequence");

?>
