--TEST--
DB_ldap2::simpleQuery test
--SKIPIF--
<?php chdir(dirname(__FILE__)); include("skipif.inc"); ?>
--FILE--
<?php
include("mktable.inc");
include("../simplequery.inc");
?>
--EXPECT--
resource
