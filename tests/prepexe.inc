<?php

$dbh->setErrorHandling(PEAR_ERROR_DIE);
$sth1 = $dbh->prepare(
    array(
	array(
	    'dn' => '?',
	    'objectClass' => array('top', 'person'),
	    'cn' => '?',
	    'sn' => 'One'
	), 
	'action' => 'add'
    )
);
$sth2 = $dbh->prepare(
    array(
	array(
	    'dn' => '?',
	    'objectClass' => '?',
	    'cn' => '?',
	    'sn' => 'Two'
	), 
	'action' => 'add'
    )
);
$sth3 = $dbh->prepare(
    array(
	array(
	    'dn' => '?',
	    'objectClass' => '?',
	    'cn' => '?',
	    'sn' => 'Three',
	    'description' => '&'
	), 
	'action' => 'add'
    )
);
print "sth1,sth2,sth3 created\n";
$tmpfile = tempnam("/tmp", "phptmp");
register_shutdown_function("my_shutdown");
$fp = fopen($tmpfile, "w");
fwrite($fp, "opaque\nplaceholder\ntest");
fclose($fp);
if (($res = $dbh->execute($sth1, array('cn=One,dc=example,dc=com', 'One'))) == DB_OK) {
    print "sth1 executed\n";
    $dbh->freeResult($sth1);
}
if (($res = $dbh->execute($sth2, array('cn=Two,dc=example,dc=com', array('top', 'person'), 'Two'))) == DB_OK) {
    print "sth2 executed\n";
    $dbh->freeResult($sth2);
}
if (($res = $dbh->execute($sth3, array('cn=Three,dc=example,dc=com', array('top', 'person'), 'Three', $tmpfile))) == DB_OK) {
    print "sth3 executed\n";
    $dbh->freeResult($sth3);
}

$sth4 = $dbh->prepare("objectClass=?");
print "sth4 created\n";
$res = $dbh->execute($sth4, '*');
print "sth4 executed\n";
print "results:\n";
while ($row = $res->fetchRow(DB_FETCHMODE_ORDERED)) {
    print implode(" - ", $row) . "\n";
}
$dbh->freeResult($sth4);

print "sth5 created\n";
$sth5 = $dbh->prepare(array("objectClass=?", "action"=>"list", "attributes"=>array("cn", "sn")));
$res = $dbh->execute($sth5, '*');
print "sth5 executed\n";
print "results:\n";
while ($row = $res->fetchRow(DB_FETCHMODE_ORDERED)) {
    print implode(" - ", $row) . "\n";
}
$dbh->freeResult($sth5);

print "sth6 created\n";
$sth6 = $dbh->prepare(array("objectClass=?", "action"=>"list", "attributes"=>array("dn")));
$res = $dbh->execute($sth6, '*');
print "sth6 executed\n";
print "results:\n";
while ($row = $res->fetchRow(DB_FETCHMODE_ORDERED)) {
    print implode(" - ", $row) . "\n";
}
$dbh->freeResult($sth6);

function my_shutdown() {
    global $tmpfile;
    unlink($tmpfile);
}

?>
