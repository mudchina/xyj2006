// sgzl
// ·ÉÌìÓù½£½£·¨£¬

/*
ËÉº×½£·¨    dodge  -5    parry  -5    damage  25
ÊñÉ½ÅÉÕòÉ½¾ø¼¼£¬¹²ÁùÊ½£º
*/

//²ÔËÉÓ­¿Í¡¡ÔÆ¹Èº×·å¡¡ÇàÉ½ÒşÒş¡¡
//°×º×ÕñÓğ¡¡Ğ¯ÊÖÈëÔÆ¡¡ÍËÒşÏÉÏç  

inherit SKILL;


mapping *action = ({
	([	"name":			"²ÔËÉÓ­¿Í",
		"action":
"$NÌøµ½¿ÕÖĞ,ÊÖÖĞ$w½ôÎÕ£¬Ïò$nÅüÈ¥£¬¶¼ÓĞËÆ¿ªÉ½´óµ¶Ò»°ã£¬ºÃÒ»Á¦µÀĞÛºñµÄ¡¸²ÔËÉÓ­¿Í¡¹",
		"dodge":		-10,
		"parry":		20,
		"damage":		25,
		"damage_type":		"ÅüÉË"
	]),
	([	"name":			"ÔÆ¹Èº×·å",
		"action":
"Ö»¼û$N×óÊÖ¸¨½££¬Ïò¿ÕÖĞÎè½££¬ÊÖÖĞ$wÏò$nµÄÈ«Éí¿³È¥\n"
"ÕıÊÇÒ»ÕĞ¡¸ÔÆ¹Èº×·å¡¹£¡",
		"dodge":		  24,
		"parry":		-19,
		"damage":		  25,
		"damage_type":		"¿³ÉË"
	]),
        ([      "name":                 "ÇàÉ½ÒşÒş",
                "action":
"$N·ÉÉíÉÏÇ°£¬ÊÖÖĞ$w¼²Îè£¬Ò»ÕĞ¡¸ÇàÉ½ÒşÒş¡¹»Ã³öÍÅÍÅ½£Ã¢£¬½«$n½ô½ô¹üÔÚÆäÖĞ",
		    "dodge":		 -15,
                "parry":           -15,
                "damage":          35,
                "damage_type":          "ÅüÉË"
        ]),
        ([      "name":                 "°×º×ÕñÓğ",
                "action":
"$N´òµ½ĞË·¢£¬İëµØÀïÒ»ÉùÇåĞ¥£¬ÊÖÖĞ$w¼±ËÙÏò$nµÄ$l´ÌÈ¥£¡ÕâÕĞÉ½±Àº£Ğ¥°ãµÄ¡¸°×º×ÕñÓğ¡¹ÍêÈ«½«$n¾ª´ôÁË",
                "dodge":                15,
                "parry":                15,
                "damage":               35,
                "damage_type":          "´ÌÉË"
        ]),
        ([      "name":                 "Ğ¯ÊÖÈëÔÆ",
                "action":
"Ö»¼û$Nµ¥×ãÀëµØ£¬Ê¹³öÒ»ÕĞ¡¸Ğ¯ÊÖÈëÔÆ¡¹£¬ÊÖÖĞ$w¼±ËÙ·É½ø£¬Åü³ö²ã²ã½£Æø£¬Ö±Ïò$nµÄ$lÅüÈ¥",
                "dodge":                -10,
                "parry":                -10,
                "damage":               25,
                "damage_type":          "´ÌÉË"
        ]),
        ([      "name":                 "ÍËÒşÏÉÏç",
                "action":
"$N¿ìËÙÇ°½ø£¬Ò»Ê½¡¸ÍËÒşÏÉÏç¡¹£¬ÉíËæ½£Æğ£¬Ïò$nÈ«Éí»·³ö¶à³õ½£Ã¢£¬ÕĞÕĞÊÆÈô·ÉÁú¾íÉí£¬$nÄÄÀïÉÁ±ÜµÃ¹ı",
		"dodge":	          -15,
		"parry":		15,
		"damage":		20,
		"damage_type":		"´ÌÉË"
	])
});
int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦ĞŞÎª²»¹»Éî£¬ÎŞ·¨Ñ§Ï°ËÉº×½£·¨¡£\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "sword" )
		return notify_fail("Äã±ØĞëÏÈÕÒÒ»±ú½£²ÅÄÜÁ·Ï°½£·¨¡£\n");
	return 1;
}

int practice_skill(object me)
{
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("songhe-sword");

	if (dod<swo/2)
		return notify_fail("ÄãµÄÉí·¨¸ú²»ÉÏ½£·¨£¬Á·ÏÂÈ¥ºÜ¿ÉÄÜ»áÉËµ½×Ô¼º¡£\n");
	if ((int)me->query("kee") < 30)
		return notify_fail("ÄãÌåÖÊÇ·¼Ñ£¬Ç¿Á·ËÉº×½£·¨ÓĞº¦ÎŞÒæ¡£\n");
	if ((int)me->query("force") < 5)
		return notify_fail("ÄãÄÚÁ¦²»×ã£¬Ç¿Á·ËÉº×½£·¨ÓĞ×ß»ğÈëÄ§µÄÎ£ÏÕ¡£\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("$NÄ¬Ä¬»ØÒäÁËÒ»»á¶ù£¬È»ºóÁ·ÁËÒ»±éËÉº×½£·¨¡£\n", me);
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

string perform_action_file(string func)
{
        return CLASS_D("shushan") + "/songhe-sword/"+func;
}
ÿÿ
