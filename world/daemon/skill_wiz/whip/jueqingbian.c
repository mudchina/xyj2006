// jueqing-bian.c
// ¾øÇé±Þ·¨
// Juney: 07/04/97: Genesis.
/*¾øÇé±Þ·¨Îª³ÕÃÎËù´´£¬±Þ·¨²øÃàÈçË¿£¬ÈçÇé°®»ÓÖ®²»È¥£¬¶ãÖ®²»µÃ£¬Ö±½ÐÉúËÀÏàÐí¡£
*/
inherit SKILL;
mapping *action =
({
([
"action" : "Ö»¼û$NÏËÑü¼±×ª£¬ð©ÍóÇá¶¶£¬Ò»Ê½¡¸ÌìµØË«·É¡¹£¬$wÔÚÉíÅÏ»¯×÷Á½µÀ·Éºç",
"dodge"  : -5,
"damage" : 20,
"parry"  : -10,
"lvl"         : 0,
"skill_name"  : "ÌìµØË«·É",
"damage_type" : "¸îÉË",
]),
([
"action" : 
"$NÄ¬ÔË±ùÐÄ¾ö£¬Ê¹³ö¡¸¼¸»Øº®Êî¡¹£¬Ò»ÂÆºöÀäºöÈÈµÄÕæÆøÑØ$w¼¤Éä¶øÀ´£¬¾¶Í¸$nµ¤Ìï°ÙÂö",
"dodge"  : -10,
"damage" : 30,
"parry"  : 5,
"lvl"         : 10,
"skill_name"  : "¼¸»Øº®Êî",
"damage_type" : "ÄÚÉË",
]),
([
"action" : 
"$NÒ»Ê½¡¸¾ýÓ¦ÓÐÓï¡¹£¬ÉñÉ«Æà³þã¯È»£¬$wÐ±Ð±Îè³ö£¬$nÐÄÖÐÒ»ÁÝ£¬Ö»¾õµÃÕâÄ¿¹âËÆÔøÏàÊ¶£¬È´ÓÖËµ²»ÉÏÀ´",
"dodge"  : -5,
"damage" : 20,
"parry"  : 5,
"lvl"         : 20,
"skill_name"  : "¾ýÓ¦ÓÐÓï",
"damage_type" : "´ÌÉË",
]),
([
"action" : 
"$NÏ¼ÐäÂý´¹£¬Á«²½¼±Ç÷£¬ÊÖÖÐ$wËÆÓ°ËæÐÎ£¬Ò»ÕÐ¡¸Ö»Ó°ÏòË­¡¹ÓúÏÔÂäÂäÓûÍù£¬½Ã½Ã²»Èº",
"dodge"  : -10,
"damage" : 30,
"parry"  : -10,
"lvl"         : 30,
"skill_name"  : "Ö»Ó°ÏòË­",
"damage_type" : "²ÁÉË",
]),
([
"action" : 
"$NÐìÐìÎè¶¯$w£¬È´ÊÇÒ»ÕÐ¡¸ÍòÀï²ãÔÆ¡¹£¬Ö»¼ûÕÐ¶ÏÒâÁ¬£¬²øÃàÍñ×ª£¬Ò»±ÞÎ´¾ø£¬±ãÒþÒþÓÐÍò±ÞÏàËæ",
"dodge"  : 0,
"damage" : 20,
"parry"  : 0,
"lvl"         : 40,
"skill_name"  : "ÍòÀï²ãÔÆ",
"damage_type" : "¸îÉË",
]),
([
"action" : 
"$NÒ»Ê½¡¸Ç§É½ÄºÑ©¡¹£¬$w»ÓÈ÷×ÔÈç£¬ö®Ê±¼äç­Ñ©·×·×£¬½¿ÈçÁøÐõ£¬ÈõËÆÀæ»¨£¬ÃÜÃÜ¹ü×¡$nÈ«Éí"
,
"dodge"  : -10,
"damage" : 25,
"parry"  : -10,
"lvl"         : 50,
"skill_name"  : "Ç§É½ÄºÑ©",
"damage_type" : "´ÌÉË",
]),
([
"action" : 
"Ö»¼û$NÒ»Â·¡¸¼ÅÄ¯óï¹Ä¡¹£¬$w»Ø·çÎèÑ©£¬°µºÏÔÏÀí£¬ËäÎÞË¿ÖñÖ®Òô£¬·´µ¹±ðÓÐÓÄ³î°µºÞÉú£¬´ËÊ±ÎÞÉùÊ¤ÓÐÉù",
"dodge"  : -10,
"damage" : 20,
"parry"  : -10,
"lvl"         : 60,
"skill_name"  : "¼ÅÄ¯óï¹Ä",
"damage_type" : "¸îÉË",
]),
([
"action" : 
"$NÒ»Ê½¡¸»ÄÑÌÆ½³þ¡¹£¬ÊÖÖÐ$wÍÌÍÂ²»¶¨£¬·Â·ðÒ»²ãÇáÑÌ±¡ÎíÆ®ÉÏ$n¼çÍ·£¬Èô¼´ÈôÀë£¬ËÆÕæËÆ»Ã£¬¼«¾¡ã­âü°§ÑÞÖ®ÃÀ",
"dodge"  : -20,
"damage" : 30,
"parry"  : 0,
"lvl"         : 70,
"skill_name"  : "»ÄÑÌÆ½³þ",
"damage_type" : "¸îÉË",
]),
([
"action" : 
"$NÒ»Éù½¿ß³£¬$wÉÏÄÚ¾¢¹á×¢£¬½ÃØ²·ÉÎè£¬Ò»Â·¡¸ÝºÑà»ÆÍÁ¡¹Ëù¹ýÖ®´¦ÂäÓ¢çÍ·×£¬ºìÏûÏã¶Ï£¬¾¢·çÖ»¹ÎµÃ$nÁ³¼ÕÉúÍ´",
"dodge"  : 0,
"damage" : 30,
"parry"  : 10,
"lvl"         : 80,
"skill_name"  : "ÝºÑà»ÆÍÁ",
"damage_type" : "ÄÚÉË",
]),
([
"action" : 
"ºöÈ»¼ä$N±ÞÊÆ¶¸±ä£¬$wä¯Àì¶Ù´ì£¬¹ÅÒâ°»È»£¬Ò»Ê½¡¸Ç§ÇïÍò¹Å¡¹ÈçÔÂÖ®Êï£¬ÈçÆøÖ®Çï£¬×ÝÓÐÇ§ÔØÇé³î£¬Òà»¯ÓÚÕâÒ»ÕÐÖ®ÖÐ",
"dodge"  : -10,
"damage" : 20,
"parry"  : 0,
"lvl"         : 90,
"skill_name"  : "Ç§ÇïÍò¹Å",
"damage_type" : "´ÌÉË",
]),
([
"action" : 
"$NÒ»Ê½¡¸ÇéÊÇºÎÎï¡¹£¬±ÞÒâç×ç¹²øÃà£¬ÈçÆüÈçËß£¬ÓÌËÆË«Ë¿Íø£¬ÖÐÓÐÇ§Ç§½á£¬Ö±½Ì$n¼ôÖ®²»¶Ï£¬ÀíÖ®»¹ÂÒ",
"dodge"  : -10,
"damage" : 20,
"parry"  : -10,
"lvl"         : 100,
"skill_name"  : "ÇéÊÇºÎÎï",
"damage_type" : "¸îÉË",
]),
([
"action" : 
"$NÐäÎèÊ±»ÃÆð»¨ÓêÂúÌì£¬±ÞÂä´¦»¯×÷¶ÏÏ¼Ç§ÂÆ£¬Ò»Ê½¡¸ÉúËÀÏàÐí¡¹±ÞÈËºÏÒ»£¬×Å×ÅÇÀ¹¥£¬È«È»²»¹Ë$n½øÕÐ",
"dodge"  : -20,
"damage" : 30,
"parry"  : 10,
"lvl"         : 110,
"skill_name"  : "ÉúËÀÏàÐí",
"damage_type" : "´ÌÉË",
]),
});

/*
mapping *action_male =
({
([
"action" : "Ö»¼û$NÉíÐÎ¼²×ª£¬ÊÖÍóÇá¶¶£¬Ò»Ê½¡¸ÌìµØË«·É¡¹£¬$wÔÚÉíÅÏ»¯×÷Á½µÀ·Éºç",
"dodge"  : 20,
"damage" : 20,
"force"  : 125,
"lvl"         : 0,
"skill_name"  : "ÌìµØË«·É",
"damage_type" : "¸îÉË",
]),
([
"action" : 
"$NÄ¬ÔË±ùÐÄ¾ö£¬Ê¹³ö¡¸¼¸»Øº®Êî¡¹£¬Ò»ÂÆºöÀäºöÈÈµÄÕæÆøÑØ$w¼¤Éä¶øÀ´£¬¾¶Í¸$nµ¤Ìï°ÙÂö",
"dodge"  : 20,
"damage" : 30,
"force"  : 150,
"skill_name" : "¼¸»Øº®Êî",
"damage_type" : "ÄÚÉË",
]),
([
"action" : 
"$NÒ»Ê½¡¸¾ýÓ¦ÓÐÓï¡¹£¬ÉñÉ«Æà³þã¯È»£¬$wÐ±Ð±»Ó³ö£¬$nÐÄÖÐÒ»ÁÝ£¬Ö»¾õµÃÕâÄ¿¹âËÆÔøÏàÊ¶£¬È´Ó
ÖËµ²»ÉÏÀ´",
"dodge"  : 25,
"damage" : 40,
"force"  : 175,
"lvl"         : 20,
"skill_name"  : "¾ýÓ¦ÓÐÓï",
"damage_type" : "´ÌÉË",
]),
([
"action" : 
"$NÔÆÐäÂý´¹£¬Á«²½¼±Ç÷£¬ÊÖÖÐ$wÈçÓ°ËæÐÎ£¬Ò»ÕÐ¡¸Ö»Ó°ÏòË­¡¹ÓúÏÔÂäÂäÓûÍù£¬½Ã½Ã²»Èº",
"dodge"  : 25,
"damage" : 50,
"force"  : 200,
"lvl"         : 30,
"skill_name"  : "Ö»Ó°ÏòË­",
"damage_type" : "²ÁÉË",
]),
([
"action" : 
"$NÐìÐìÎè¶¯$w£¬È´ÊÇÒ»ÕÐ¡¸ÍòÀï²ãÔÆ¡¹£¬Ö»¼ûÕÐ¶ÏÒâÁ¬£¬²øÃàÍñ×ª£¬Ò»±ÞÎ´¾ø£¬±ãÒþÒþÓÐÍò±ÞÏ
àËæ",
"dodge"  : 30,
"damage" : 60,
"force"  : 225,
"lvl"         : 40,
"skill_name"  : "ÍòÀï²ãÔÆ",
"damage_type" : "¸îÉË",
]),
([
"action" : 
"$NÒ»Ê½¡¸Ç§É½ÄºÑ©¡¹£¬$w»ÓÈ÷×ÔÈç£¬ö®Ê±¼äç­Ñ©·×·×£¬ÈáÈçÁøÐõ£¬ÈõËÆÀæ»¨£¬ÃÜÃÜ¹ü×¡$nÈ«Éí"
,
"dodge"  : 30,
"damage" : 70,
"force"  : 250,
"lvl"         : 50,
"skill_name"  : "Ç§É½ÄºÑ©",
"damage_type" : "´ÌÉË",
]),
([
"action" : 
"Ö»¼û$NÒ»Â·¡¸¼ÅÄ¯óï¹Ä¡¹£¬$w»Ø·çÎèÑ©£¬°µºÏÔÏÀí£¬ËäÎÞË¿ÖñÖ®Òô£¬·´µ¹±ðÓÐÓÄ³î°µºÞÉú£¬´ËÊ
±ÎÞÉùÊ¤ÓÐÉù",
"dodge"  : 35,
"damage" : 80,
"force"  : 275,
"lvl"         : 60,
"skill_name"  : "¼ÅÄ¯óï¹Ä",
"damage_type" : "¸îÉË",
]),
([
"action" : 
"$NÒ»Ê½¡¸»ÄÑÌÆ½³þ¡¹£¬ÊÖÖÐ$wÍÌÍÂ²»¶¨£¬·Â·ðÒ»²ãÇáÑÌ±¡ÎíÆ®ÉÏ$n¼çÍ·£¬Èô¼´ÈôÀë£¬ËÆÕæËÆ»Ã£
¬¼«¾¡ã­âü°§ÑÞÖ®ÃÀ",
"dodge"  : 35,
"damage" : 80,
"force"  : 300,
"lvl"         : 70,
"skill_name"  : "»ÄÑÌÆ½³þ",
"damage_type" : "¸îÉË",
]),
([
"action" : 
"$NÒ»ÉùÇåÐ¥£¬$wÉÏÄÚ¾¢¹á×¢£¬½ÃØ²·ÉÎè£¬Ò»Â·¡¸ÝºÑà»ÆÍÁ¡¹Ëù¹ýÖ®´¦ÂäÓ¢çÍ·×£¬ºìÏûÏã¶Ï£¬¾¢·
çÖ»¹ÎµÃ$nÁ³¼ÕÉúÍ´",
"dodge"  : 40,
"damage" : 90,
"force"  : 325,
"lvl"         : 80,
"skill_name"  : "ÝºÑà»ÆÍÁ",
"damage_type" : "ÄÚÉË",
]),
([
"action" : 
"ºöÈ»¼ä$N±ÞÊÆ¶¸±ä£¬$wä¯Àì¶Ù´ì£¬¹ÅÒâ°»È»£¬Ò»Ê½¡¸Ç§ÇïÍò¹Å¡¹ÈçÔÂÖ®Êï£¬ÈçÆøÖ®Çï£¬×ÝÓÐÇ§Ô
ØÇé³î£¬Òà»¯ÓÚÕâÒ»ÕÐÖ®ÖÐ",
"dodge"  : 40,
"damage" : 90,
"force"  : 350,
"lvl"         : 90,
"skill_name"  : "Ç§ÇïÍò¹Å",
"damage_type" : "´ÌÉË",
]),
([
"action" : 
"$NÒ»Ê½¡¸ÇéÊÇºÎÎï¡¹£¬±ÞÒâç×ç¹²øÃà£¬ÈçÆüÈçËß£¬ÓÌËÆË«Ë¿Íø£¬ÖÐÓÐÇ§Ç§½á£¬Ö±½Ì$n¼ôÖ®²»¶Ï£
¬ÀíÖ®»¹ÂÒ",
"dodge"  : 45,
"damage" : 100,
"force"  : 375,
"lvl"         : 100,
"skill_name"  : "ÇéÊÇºÎÎï",
"damage_type" : "¸îÉË",
]),
([
"action" : 
"$NÐäÎèÊ±»ÃÆð»¨ÓêÂúÌì£¬±ÞÂä´¦»¯×÷¶ÏÏ¼Ç§ÂÆ£¬Ò»Ê½¡¸ÉúËÀÏàÐí¡¹±ÞÈËºÏÒ»£¬×Å×ÅÇÀ¹¥£¬È«È»²
»¹Ë$n½øÕÐ",
"dodge"  : 45,
"damage" : 100,
"force"  : 400,
"lvl"         : 110,
"skill_name"  : "ÉúËÀÏàÐí",
"damage_type" : "´ÌÉË",
]),
});

mapping *action_sanshou =
({
([
"action" : 
"µÚÒ»ÕÐ¡¸ÎÞ¿×²»Èë¡¹£¬ÄËÊÇÏò¶ÔÊÖÈ«Éí¸÷´¦´óÑ¨½ø¹¥£¬$nÖ»¾õµÃÏã·çÏ®Ï®£¬ÖÜÉí°Ùº¡¶¼ÊÇ$wµÄÓ
°×Ó",
"dodge"  : -30,
"damage" : 80,
"force"  : 350,
"lvl"         : 100,
"skill_name"  : "ÎÞ¿×²»Èë",
"damage_type" : "´ÌÉË",
]),
([
"action" : 
"½ô¸ú×Å$NÊ¹³ö¡¸ÎÞËù²»ÖÁ¡¹£¬ËäÎªÒ»ÕÐ£¬ÆäÊµÇ§Í·ÍòÐ÷£¬$wÍ¬Ê±µãÏò$nÖÜÉíÖî´¦Æ«ÃÅÑ¨µÀ",
"dodge"  : -30,
"damage" : 90,
"force"  : 375,
"lvl"         : 100,
"skill_name"  : "ÎÞËù²»ÖÁ",
"damage_type" : "´ÌÉË",
]),
([
"action" : 
"µÚÈýÕÐ¡¸ÎÞËù²»Îª¡¹£¬²»ÔÙµãÑ¨£¬¶ø×¨»÷$nÑÛ¾¦¡¢ÑÊºí¡¢Ð¡¸¹¡¢ÏÂÒõµÈÖî°ãÈáÈíÖ®´¦£¬Òõ¶¾ÎÞ±
È",
"dodge"  : -30,
"damage" : 100,
"force"  : 400,
"lvl"         : 100,
"skill_name"  : "ÎÞËù²»Îª",
"damage_type" : "´ÌÉË",
]),
});

*/
int valid_enable(string usage) {
    return usage == "whip" || usage == "parry";
}

int valid_learn(object me) {
    if ((int)me->query_skill("moonshentong",1) < 40 )
	return notify_fail("ÄãµÄÔ²ÔÂÐÞÐÄ·¨ÎªÉÐÇ³£¬Ã»·¨Ñ§¾øÇé±Þ£¡\n");
    if ((int)me->query_skill("moondance", 1) < 50)
        return notify_fail("ÄãµÄÀäÔÂÄýÏãÎèÐÞÎªÉÐÇ³£¬Ã»·¨Ñ§¾øÇé±Þ£¡\n");
    return 1;
}
/*
string query_skill_name(int level) {
    int i;
    for (i=sizeof(action)-1; i>=0; i--)
	if (level >= action[i]["lvl"])
	    return action[i]["skill_name"];
}
*/

mapping query_action(object me, object weapon) 
{
/*
    int level = (int)(me->query_skill("jueqing-bian", 1));
    int i;
    for (i=sizeof(action); i>=1; i--)
	if (level > action[i-1]["lvl"])
	    return action[NewRandom(i, 20, level/5)];
*/
	return action[random(sizeof(action))];

}

int practice_skill(object me) {
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon")) ||
	(string)(weapon->query("skill_type")) != "whip")
	return notify_fail("ÄãÕâ²ÅÏëÆðÊÖÀïÃ»±Þ×Ó£¬ÔõÃ´Á·¾øÇé±Þ°¡£¿ :)\n");
    if ((int)(me->query("kee")) < 50)
	return notify_fail("ÄãÒÑ¾­¾«Æ£Á¦½ß£¬Ã»·¨¶ùÁ·ÏÂÈ¥À²£¡\n");
    me->receive_damage("kee", 30);
    return 1;
}
/*
string perform_action_file(string action) {
    return __DIR__"jueqing-bian/"+action;
}
*/
