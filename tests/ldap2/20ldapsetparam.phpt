--TEST--
DB_ldap2::ldapSetParam test
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

print "base DN: ". $dbh->ldapGetParam("base_dn"). "\n";
print "result: ". join(' - ', $dbh->getCol(array("objectClass=*", "attributes"=>array("dn")))). "\n";

$dbh->ldapSetParam("base_dn", "cn=One,dc=example,dc=com");

print "base DN: ". $dbh->ldapGetParam("base_dn"). "\n";
print "result: ". join(' - ', $dbh->getCol(array("objectClass=*", "attributes"=>array("dn")))). "\n";

$dn = $dbh->getOne(array("objectClass=*", "attributes"=>array("dn"))). "\n";

print "explode attributes: ". join(' - ', $dbh->ldapExplodeDN($dn)). "\n";
print "explode values: ". join(' - ', $dbh->ldapExplodeDN($dn,1)). "\n";

?>
--EXPECT--
base DN: dc=example,dc=com
result: dc=example,dc=com - cn=One,dc=example,dc=com
base DN: cn=One,dc=example,dc=com
result: cn=One,dc=example,dc=com
explode attributes: cn=One - dc=example - dc=com
explode values: One - example - com
