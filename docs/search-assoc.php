<?

$dsn = "ldap3://ldap.openldap.org/dc=OpenLDAP,dc=org";

require_once 'DB.php';

function die_error_message ($message) {
    global $log, $PHP_SELF;
    print "ERR\n";
    echo $message, "\n";
    die();
}
		
/* Handler dla b³êdów DB */
function db_error_handler ($error) {
    die_error_message("$error->message ($error->code) $error->userinfo");
}
		    
$db = DB::connect($dsn);
if (DB::isError($db)) {
    db_error_handler($db);
}
$db->setErrorHandling(PEAR_ERROR_CALLBACK, 'db_error_handler');

$query = "(objectClass=*)";
$base = "ou=People,dc=OpenLDAP,dc=org";

$db->setFetchMode(DB_FETCHMODE_ASSOC);
var_dump($db->getAll(array($query, base_dn=>$base, action=>'read')));
