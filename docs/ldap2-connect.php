<?

$dsn = "ldap2://db.debian.org/dc=debian,dc=org";

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

if ($db->ldapGetOption(LDAP_OPT_PROTOCOL_VERSION, $version))
    echo "Using protocol version $version\n";
else
    echo "Unable to determine protocol version\n";

$query = "(objectClass=*)";
$base = "ou=users,dc=debian,dc=org";

$db->setFetchMode(DB_FETCHMODE_ORDERED);
var_dump($db->getAll(array($query, base_dn=>$base, action=>'read')));
