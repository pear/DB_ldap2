--TEST--
DB_ldap2::sequences
--SKIPIF--
<?php chdir(dirname(__FILE__)); require "skipif.inc"; ?>
--FILE--
<?php
include("mktable.inc");
require "../sequences.inc";
?>
--EXPECT--
DB Error: no such table <- good error catched
DB Error: no such table
DB Error: no such table <- good error catched
a=1
b=2
b-a=1
c=1
d=1
e=1
