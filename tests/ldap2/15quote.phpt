--TEST--
DB_ldap2::escape data test
--SKIPIF--
<?php chdir(dirname(__FILE__)); include("skipif.inc"); ?>
--FILE--
<?php
include './connect.inc';
include './mktable.inc';
$dbh->setErrorHandling(PEAR_ERROR_CALLBACK, 'debug_die');

$data = $dbh->getAll(array('objectClass=*', 'action'=>'list', 'attributes'=>array('dn')));
foreach($data as $entry) {
    var_dump($entry);
    $dbh->simpleQuery(array($entry, 'action'=>'delete'));
}

$strings = array(
    "'",
    "\"",
    "\\",
    "%",
    "_",
    "''",
    "\"\"",
    "\\\\",
    "\\'\\'",
    "\\\"\\\""
);
$results = array(
    "'",
    "\\\"",
    "\\\\",
    "%",
    "_",
    "''",
    "\\\"\\\"",
    "\\\\\\\\",
    "\\\\'\\\\'",
    "\\\\\\\"\\\\\\\""
);

echo "String escape test: ";
foreach ($strings as $s) {
    $quoted = $dbh->quote($s);
    $dbh->query(
	array(
	    array(
		'dn' => "cn=$quoted,dc=example,dc=com",
		'objectClass' => array('top', 'person'),
		'cn' => $quoted,
		'sn' => '1',
	    ), 
	    'action' => 'add'
	)
    );
}
$diff = array_diff($results, $res = $dbh->getCol(array("sn=1", 'attributes'=>array('cn')),'cn'));
if (count($diff) > 0) {
    echo "FAIL\n";
    print_r($results);
    print_r($res);
} else {
    echo "OK\n";
}
die();

?>
--EXPECT--
String escape test: OK
