<?php
ini_set('include_path', realpath(dirname(__FILE__) . "/../..") . ":.:" . ini_get('include_path'));

//define('DRIVER_DSN', 'ldap2://127.0.0.1/dc=example,dc=com');
define('DRIVER_DSN', 'ldap2://uid=root,ou=adm,dc=example,dc=com:secret@127.0.0.1/dc=example,dc=com');
//define('DRIVER_DSN', 'pgsql://postgres@localhost/test');
//define('DRIVER_DSN', 'mysql://root@localhost/test');
//define('DRIVER_DSN', 'oci8://system:manager@');
?>