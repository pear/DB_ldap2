--TEST--
DB_ldap2::fetch test
--SKIPIF--
<?php chdir(dirname(__FILE__)); include("skipif.inc"); ?>
--FILE--
<?php
include("mktable.inc");
//include("../fetchrow.inc");
include("../fetchmodes.inc");
?>
--EXPECT--
testing fetchmodes: fetchrow default default
array(3) {
  ["dn"]=>
  string(17) "dc=example,dc=com"
  ["objectclass"]=>
  array(2) {
    [0]=>
    string(3) "top"
    [1]=>
    string(6) "domain"
  }
  ["dc"]=>
  string(4) "test"
}
testing fetchmodes: fetchinto default default
array(3) {
  ["dn"]=>
  string(17) "dc=example,dc=com"
  ["objectclass"]=>
  array(2) {
    [0]=>
    string(3) "top"
    [1]=>
    string(6) "domain"
  }
  ["dc"]=>
  string(4) "test"
}
testing fetchmodes: fetchrow ordered default
array(3) {
  [0]=>
  string(3) "top"
  [1]=>
  string(6) "domain"
  [2]=>
  string(4) "test"
}
testing fetchmodes: fetchrow assoc default
array(3) {
  ["dn"]=>
  string(17) "dc=example,dc=com"
  ["objectclass"]=>
  array(2) {
    [0]=>
    string(3) "top"
    [1]=>
    string(6) "domain"
  }
  ["dc"]=>
  string(4) "test"
}
testing fetchmodes: fetchrow ordered default with assoc specified
array(3) {
  ["dn"]=>
  string(17) "dc=example,dc=com"
  ["objectclass"]=>
  array(2) {
    [0]=>
    string(3) "top"
    [1]=>
    string(6) "domain"
  }
  ["dc"]=>
  string(4) "test"
}
testing fetchmodes: fetchrow assoc default with ordered specified
array(3) {
  [0]=>
  string(3) "top"
  [1]=>
  string(6) "domain"
  [2]=>
  string(4) "test"
}
testing fetchmodes: fetchinto ordered default
array(3) {
  [0]=>
  string(3) "top"
  [1]=>
  string(6) "domain"
  [2]=>
  string(4) "test"
}
testing fetchmodes: fetchinto assoc default
array(3) {
  ["dn"]=>
  string(17) "dc=example,dc=com"
  ["objectclass"]=>
  array(2) {
    [0]=>
    string(3) "top"
    [1]=>
    string(6) "domain"
  }
  ["dc"]=>
  string(4) "test"
}
testing fetchmodes: fetchinto ordered default with assoc specified
array(3) {
  ["dn"]=>
  string(17) "dc=example,dc=com"
  ["objectclass"]=>
  array(2) {
    [0]=>
    string(3) "top"
    [1]=>
    string(6) "domain"
  }
  ["dc"]=>
  string(4) "test"
}
testing fetchmodes: fetchinto assoc default with ordered specified
array(3) {
  [0]=>
  string(3) "top"
  [1]=>
  string(6) "domain"
  [2]=>
  string(4) "test"
}
