<?php
require_once "./connect.inc";

$dbh->expectError(DB_ERROR_NOSUCHTABLE);
$data = $dbh->getAll(array('objectClass=*', 'action'=>'search', 'attributes'=>array('dn')), DB_FETCHMODE_ASSOC);
$dbh->popExpect();
if (!DB::isError($data)) {

    function usort_ldap_dn_desc ($a, $b) {
	$na = count(ldap_explode_dn($a["dn"], 0));
	$nb = count(ldap_explode_dn($b["dn"], 0));
	if ($na == $nb) return 0;
	return $na > $nb ? -1 : 1;
    }

    usort($data, "usort_ldap_dn_desc");
    foreach($data as $entry) {
	$dbh->simpleQuery(array($entry, 'action'=>'delete'));
    }
}

$dbh->setErrorHandling(PEAR_ERROR_CALLBACK, 'debug_die');
$test_mktable_query = array(
    array(
	'dn' => 'dc=example,dc=com',
	'objectClass' => array('top', 'domain'),
	'dc' => 'test'
    ), 
    'action' => 'add'
);
$dbh->query($test_mktable_query);

?>
