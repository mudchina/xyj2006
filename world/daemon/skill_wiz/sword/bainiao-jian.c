// sgzl
// °ÙÄñ½£·¨£¬

/*
°ÙÄñ½£·¨    dodge  -5    parry  -5    damage  20
Ñ©É½ÅÉ¸ßÊÖÄ£·Â°ÙÇİ²«¶·µÄ¶¯×÷¶øµÃ
*/

// ´óÅôÕ¹³á,Ó¥»÷³¤¿Õ,·ïÎè¾ÅÌì,ĞÛ¼¦±¨Ïş,ğÊÁ¢ÔÆ¶Ë,ºè·ÉÌìÍâ
// ¶Å¾éÌäÑª,ÑàÓï±¨´º,º×Ó°º®ÌÁ,¿×È¸¿ªÆÁ,ğĞğÄÑ§Éà,Ô§ÑìÏ·Ë®

inherit SKILL;


mapping *action = ({
	([	"name":			"´óÅôÕ¹³á",
		"action":
"$NÊÖÖĞ$w´ó¿ª´óãØ£¬Ã¿Ò»½£Ïò$nÅüÈ¥£¬¶¼ÓĞËÆ¿ªÉ½´ó¸«Ò»°ã£¬ºÃÒ»ÕĞÊÆµÀĞÛµÄ¡¸´óÅôÕ¹³á¡¹",
		"dodge":		-15,
		"parry":		10,
		"damage":		20,
		"damage_type":		"ÅüÉË"
	]),
	([	"name":			"Ó¥»÷³¤¿Õ",
		"action":
"Ö»¼û$NÉíĞÎÉÔÍË£¬ÓÒ×ãµãµØĞ±Ğ±Ô¾Æğ£¬ÊÖÖĞ$w±ÊÖ±µØÏò$nµÄ$l´ÌÈ¥\n"
"ÕıÊÇÒ»ÕĞ¡¸Ó¥»÷³¤¿Õ¡¹£¡",
		"dodge":		-5,
		"parry":		-10,
		"damage":		15,
		"damage_type":		"´ÌÉË"
	]),
        ([      "name":                 "·ïÎè¾ÅÌì",
                "action":
"$N·ÉÉíÉÏÇ°£¬ÊÖÖĞ$w¼²Îè£¬Ò»ÕĞ¡¸·ïÎè¾ÅÌì¡¹»Ã³öÍÅÍÅ½£Ã¢£¬½«$n½ô½ô¹üÔÚÆäÖĞ",
		"dodge":		-10,
                "parry":                -5,
                "damage":               35,
                "damage_type":          "ÅüÉË"
        ]),
        ([      "name":                 "ĞÛ¼¦±¨Ïş",
                "action":
"$N´òµ½ĞË·¢£¬İëµØÀïÒ»ÉùÇåĞ¥£¬ÊÖÖĞ$w³åÌì¶øÆğ£¬Ö±Ö¸$nµÄ$l£¡ÕâÕĞÉ½±Àº£Ğ¥°æµÄ¡¸ĞÛ¼¦±¨Ïş¡¹ÍêÈ«½«$n¾ª´ôÁË",
                "dodge":                -10,
                "parry":                -5,
                "damage":               35,
                "damage_type":          "ÅüÉË"
        ]),
        ([      "name":                 "ğÊÁ¢ÔÆ¶Ë",
                "action":
"Ö»¼û$Nµ¥×ãµãµØ£¬Ê¹³öÒ»ÕĞ¡¸ğÊÁ¢ÔÆ¶Ë¡¹£¬ÊÖÖĞ$w¼²½ø£¬»Ã³öµãµãº®ĞÇ£¬Ö±´Ì$nµÄ$l",
                "dodge":                -5,
                "parry":                -5,
                "damage":               25,
                "damage_type":          "´ÌÉË"
        ]),
        ([      "name":                 "ºè·ÉÌìÍâ",
                "action":
"$NİëÈ»Ô¾Æğ£¬Ò»Ê½¡¸ºè·ÉÌìÍâ¡¹£¬ÉíËæ½£Æğ£¬Ïò$n±³ĞÄ¼²´ÌÊı½££¬ÕĞÕĞÊÆÈô±©·çÖèÓê£¬$nÄÄÀïÉÁ±ÜµÃ¹ı",
		"dodge":		-5,
		"parry":		-5,
		"damage":		20,
		"damage_type":		"´ÌÉË"
	]),
	([	"name":			"¶Å¾éÌäÑª",
		"action":
"$N×óÊÖÄó×Å½£¾ö£¬ÓÒÊÖ½£²»×¡¶¶¶¯£¬Ò»Ê½¡¸¶Å¾éÌäÑª¡¹£¬ÊÖÖĞ$wÆ½Æ½´Ì³ö£¬\n"
"½£¼â¼±²ü£¬¸ù±¾²»Öª¹¥ÏòºÎ´¦",
		"dodge":		-15,
		"parry":		5,
		"damage":		25,
		"damage_type":		"´ÌÉË"
	]),
	([	"name":			"ÑàÓï±¨´º",
		"action":
"$NÎüÒ»¿ÚÆø£¬ÊÖÖĞÁ¬»·Æß½££¬Ò»½£¿ìËÆÒ»½££¬Ò»Ê½¡¸ÑàÓï±¨´º¡¹£¬½£·¨ÇáÁéÆ®Òİ£¬Èç·çÈçÓê°ãµÄ¹¥Ïò$nµÄ$l",
		"dodge":		-5,
		"parry":		0,
		"damage":		15,
		"damage_type":		"´ÌÉË"
	]),
	([	"name":			"º×Ó°º®ÌÁ",
		"action":
"Ö»¼û$NÉíĞÎÆ½Æ½ÂÓÆğ£¬ÉñÇéÆàÈ»£¬²»¾­Òâ¼äÓÒÊÖ$wÒ»¶¶£¬\n"
"Ò»µÀ½£ºç½«$nÍÅÍÅÕÖÔÚÆäÖĞ£¬$wÖ±±¼$nµÄ$l£¬ÕâÒ»ÕĞ¡¸º×Ó°º®ÌÁ¡¹¹ûÈ»ÈçÊ«Èç»­",
		"dodge":		-20,
		"parry":		10,
		"damage":		20,
		"damage_type":		"´ÌÉË"
	]),
        ([      "name":                 "¿×È¸¿ªÆÁ",
                "action":
"Ö»¼û$NÍì³öÊ®Êı¶ä½£»¨£¬»¯×÷Ê®ÊıµÀÎå²Ê½£ºç½«$nÕÖÔÚÆäÖĞ£¬$nÄÄÀïÊ¶µÃÕâÕĞ¡¸¿×È¸¿ªÆÁ¡¹µÄÀûº¦",
                "dodge":                -5,
                "parry":                -5,
                "damage":               25,
                "damage_type":          "´ÌÉË"
        ]),
        ([      "name":                 "ğĞğÄÑ§Éà",
                "action":
"$NÍ»È»Á³É«Í»±ä£¬ÉñÇé»¬»ü£¬½£ÕĞ±äµÃÓë$nµÄÕĞÊ½Ò»Ä£Ò»Ñù£¡È´ÓÖ´¦´¦ÖÆ×¡ÁËÄãµÄÕĞ·¨£¬\n"
"ÑÛ¼û$N$wÖ±±¼$nµÄ$l£¬$nÈ´²»ÖªÈçºÎ·À±¸ÕâÕĞ¡¸ğĞğÄÑ§Éà¡¹",
                "dodge":                -5,
                "parry":                0,
                "damage":               20,
                "damage_type":          "¸îÉË"
        ]),
        ([      "name":                 "Ô§ÑìÏ·Ë®",
                "action":
"$NÏËÑüÎ¢°Ú£¬³¤½£¼±´Ì£¬ÕâÒ»ÕĞ¡¸Ô§ÑìÏ·Ë®¡¹È¥ÊÆ¹ÌÈ»ÁèÀ÷£¬ÒÖÇÒ·ç×Ë´ÂÔ¼£¬Ö±±¼$nµÄ$l",
                "dodge":                -10,
                "damage":               25,
                "damage_type":          "´ÌÉË"
        ]),
});
int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦ĞŞÎª²»¹»Éî£¬ÎŞ·¨Ñ§Ï°°ÙÄñ½£·¨¡£\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "sword" )
		return notify_fail("Äã±ØĞëÏÈÕÒÒ»±ú½£²ÅÄÜÁ·Ï°½£·¨¡£\n");
	return 1;
}

int practice_skill(object me)
{
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("bainiao-jian");

	if (dod<swo/2)
		return notify_fail("ÄãµÄÉí·¨¸ú²»ÉÏ½£·¨£¬Á·ÏÂÈ¥ºÜ¿ÉÄÜ»áÉËµ½×Ô¼º¡£\n");
	if ((int)me->query("kee") < 30)
		return notify_fail("ÄãÌåÖÊÇ·¼Ñ£¬Ç¿Á·°ÙÄñ½£·¨ÓĞº¦ÎŞÒæ¡£\n");
	if ((int)me->query("force") < 5)
		return notify_fail("ÄãÄÚÁ¦²»×ã£¬Ç¿Á·°ÙÄñ½£·¨ÓĞ×ß»ğÈëÄ§µÄÎ£ÏÕ¡£\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("$NÄ¬Ä¬»ØÒäÁËÒ»»á¶ù£¬È»ºóÁ·ÁËÒ»±é°ÙÄñ½£·¨¡£\n", me);
	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
ÿÿ
