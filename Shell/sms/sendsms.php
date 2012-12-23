<?php 

/**
 * @author Kingster
 * @category SMS
 * @copyright 2012
 * @description Request this page with get or post params
 * @param uid = FullonSMS Username
 * @param pwd = FullonSMS Password
 * @param phone = Number to send to. Multiple Numbers separated by comma (,). 
 * @param msg = Your Message ( Upto 140 Chars)
 */

include ('fullonsms-api.php');

parse_str(implode('&', array_slice($argv, 1)), $_REQUEST);

/*
echo $_REQUEST['uid'];
echo "\n";
echo $_REQUEST['pwd'];
echo "\n";
*/
echo $_REQUEST['phone'];
echo "\n";
echo $_REQUEST['msg'];
echo "\n";

if (isset($_REQUEST['uid']) && isset($_REQUEST['pwd']) && isset($_REQUEST['phone']) && isset($_REQUEST['msg']))
{
  $res =   sendFullonSMS($_REQUEST['uid'], $_REQUEST['pwd'], $_REQUEST['phone'], $_REQUEST['msg']);
  if(is_array($res)) echo $res[0]['result'] ? "sent!\n" : "ERROR!\n";
  else echo $res;
}

?>
