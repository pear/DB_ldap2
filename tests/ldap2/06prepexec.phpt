--TEST--
DB_ldap2::prepare/execute test
--SKIPIF--
<?php chdir(dirname(__FILE__)); include("skipif.inc"); ?>
--FILE--
<?php
include("mktable.inc");
include("../prepexe.inc");
?>
--EXPECT--
sth1,sth2,sth3 created
sth1 executed
sth2 executed
sth3 executed
sth4 created
sth4 executed
results:
top - domain - test
top - person - One - One
top - person - Two - Two
top - person - Three - Three - opaque
placeholder
test
sth5 created
sth5 executed
results:
One - One
Two - Two
Three - Three
sth6 created
sth6 executed
results:
cn=One,dc=example,dc=com
cn=Two,dc=example,dc=com
cn=Three,dc=example,dc=com
