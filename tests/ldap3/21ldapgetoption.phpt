--TEST--
DB_ldap3::ldapGetOption test
--SKIPIF--
<?php chdir(dirname(__FILE__)); include("skipif.inc"); ?>
--FILE--
<?php
require "connect.inc";
if ($dbh->ldapGetOption(LDAP_OPT_PROTOCOL_VERSION, $version))
    echo "Using protocol version $version\n";
else
    echo "Unable to determine protocol version\n";

?>
--EXPECT--
Using protocol version 3
