--TEST--
DB_ldap2::affectedRows test
--SKIPIF--
<?php chdir(dirname(__FILE__)); include("skipif.inc"); ?>
--FILE--
<?php
include("mktable.inc");
// Clean table
$dbh->query(
    array(
	array(
	    'dn' => 'cn=One,dc=example,dc=com',
	    'objectClass' => array('top', 'person'),
	    'cn' => 'One',
	    'sn' => 'One',
	    'description' => '1'
	), 
	'action' => 'add'
    )
);
printf("%d after insert\n", $dbh->affectedRows());

// Affected rows by SELECT statement
$dbh->query("objectClass=*");
printf("%d after select\n", $dbh->affectedRows());

$dbh->query(array("cn=One,dc=example,dc=com", "action"=>"delete"));
printf("%d after delete\n", $dbh->affectedRows());

?>
--EXPECT--
1 after insert
0 after select
1 after delete
