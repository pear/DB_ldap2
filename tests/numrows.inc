<?php

if (!function_exists("errhandler"))
{
    function errhandler($obj)
    {
        printf("%s\n", $obj->getMessage());
    }
}

if (isset($test_error_mode)) {
    $dbh->setErrorHandling($test_error_mode);
} else {
    $dbh->setErrorHandling(PEAR_ERROR_DIE);
}
$sth = $dbh->query("objectClass=*");
if (!DB::isError($rows = $sth->numRows())) {
    print "$rows\n";
} else {
    print "\n";
}
for ($i = 0; $i < 5; $i++) {
    $sth = $dbh->query(
	array(
	    array(
		'dn' => "cn=$i,dc=example,dc=com",
		'objectClass' => array('top', 'person'),
		'cn' => $i,
		'sn' => 'a',
	    ), 
	    'action' => 'add'
	)
    );
    $sth = $dbh->query("objectClass=*");
    if (!DB::isError($rows = $sth->numRows())) {
        print "$rows\n";
    } else {
        print "\n";
    }
}
$dbh->query(array(array('dn' => 'cn=0,dc=example,dc=com'), 'action' => 'delete'));
$dbh->query(array(array('dn' => 'cn=1,dc=example,dc=com'), 'action' => 'delete'));
$dbh->query(array(array('dn' => 'cn=2,dc=example,dc=com'), 'action' => 'delete'));
$dbh->query(array(array('dn' => 'cn=3,dc=example,dc=com'), 'action' => 'delete'));
$sth = $dbh->query("objectClass=*");
if (!DB::isError($rows = $sth->numRows())) {
    print "$rows\n";
} else {
    print "\n";
}
$sth = $dbh->query("sn=b");
if (!DB::isError($rows = $sth->numRows())) {
    print "$rows\n";
} else {
    print "\n";
}
?>
