#include <ansi.h>

inherit NPC;

string test_player();

mapping *poisons = ({
	([	"name": "double_ice_poison",
		"base_amount": 100
	]),
	([	"name": "ice_poison",
		"base_amount": 50
	]),
	([	"name": "jjf_poison",
		"base_amount": 10
	]),
	([	"name": "snake_poison",
		"base_amount": 10
	]),
    ([  "name": "bp_poison",
        "base_amount": 10
    ]),
	([	"name": "moon_poison",
		"base_amount": 100
	]),
});

void create()
{
        set_name("ÎíÔ¨µÀ³¤", ({"wuyuan daozhang", "wuyuan", "daozhang","taoist"}));
        set("age", 62);
        set("gender", "ÄĞĞÔ");
        set("long",
"ÇåĞé¹ÛµÄÖ÷³Ö£¬¿´ÆğÀ´ÏÉ·çµÀ¹Ç£®\n");
        set("attitude", "peaceful");
	set("class", "taoist");
        set("combat_exp", 180000);
  set("daoxing", 800000);

        set("shen_type", 1);

        set_skill("unarmed", 90);
        set_skill("dodge", 90);
        set_skill("parry", 90);
        set_skill("whip", 90);
	set_skill("force", 90);
	set_skill("spells", 80);
	set_skill("dao", 80);
	map_skill("spells", "dao");
        set("force", 400);
	set("max_force", 400);
	set("force_factor", 10);
	set("mana", 1000);
	set("max_mana", 600);
	set("mana_factor", 30);

	set("max_kee", 800);
	set("max_sen", 700);

        set("eff_dx", 80000);
        set("nkgain", 300);

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: cast_spell, "light" :),
                (: cast_spell, "thunder" :)
        }) );

	set("inquiry", ([
		"name": "Æ¶µÀÎíÔ¨£¬±¾¹ÛÖ÷³Ö¾ÍÊÇÆ¶µÀ¡£",
		"here": "Æ¶µÀ´ÖÍ¨Ò½Êõ£¬ÒªÖÎ²¡(cure)Ò²ĞíÆ¶µÀ¿ÉÒÔÊÔÊÔ¿´¡£",
		"cure": (: test_player :),
		"ÖÎ²¡": (: test_player :),
	]));

	set("chat_chance", 20);
	set("chat_msg", ({
"ÎíÔ¨ÕæÈËÌ¾µ½£ºÄÑÄÑÄÑ£¬µÀ×îĞş£¬Äª°Ñ½ğµ¤×÷µÈÏĞ£®\n",
}) );
        setup();
        carry_object("/d/obj/weapon/whip/fuchen")->wield();
        carry_object("/d/lingtai/obj/cloth")->wear();
}

string test_player()
{
	object me=this_player(), npc=this_object();
	mapping poison;
	int i;
	int amount, duration, total;

	total=0;
	message_vision(CYN "$nÉì³öÓÒÊÖ£¬´îÔÚ$NÊÖÍóÉÏ¡£\n"NOR, me, npc);
	message_vision(CYN "¹ıÁËÆ¬¿Ì£¬$n»º»ºËµµÀ£º\n" NOR, me, npc);
	for(i=0;i<sizeof(poisons);i++) {
		poison=poisons[i];
		duration=me->query_condition(poison["name"]);
		if(duration>0) {
			amount=poison["base_amount"]*duration;
			message_vision(CYN ""+poison["name"]+"£º"+chinese_number(amount)+"Á½°×Òø,\n" NOR, me, npc);
			total+=amount;
		}
	}
	if(me->query("eff_kee")<me->query("max_kee")) {
		duration=me->query("max_kee")-me->query("eff_kee");
		amount=duration;
		message_vision(CYN "ÆøÑª£º"+chinese_number(amount)+"Á½°×Òø,\n" NOR, me, npc);
		total+=amount;
	}
	if(me->query("eff_sen")<me->query("max_sen")) {
                duration=me->query("max_sen")-me->query("eff_sen");
                amount=duration;
                message_vision(CYN "¾«Éñ£º"+chinese_number(amount)+"Á½°×Òø,\n" NOR, me, npc);
		total+=amount;
        }
	me->set_temp("cure_payment", total);
	if(total>0) {
		message_vision(CYN "Ò»¹²ĞèÒª"+chinese_number(total)+"Á½°×Òø¡£\n" NOR, me, npc);
		return "½»Ò½Ò©·Ñ°É£¡";
	}
	message_vision(CYN ""+RANK_D->query_respect(me)+"ÓÖÃ»²¡£¬ÔõÃ´ÖÎ£¿\n" NOR, me, npc);
	return "Ò»±ßÍæÈ¥£¡";
}

int accept_object(object who, object ob)
{
	object me = this_object();
	mapping poison;
	int total = who->query_temp("cure_payment");
	int value=ob->value();
	int duration,i;

	if(total==0) {
		command("say "+RANK_D->query_respect(who)+"ÕâÊÇ¸ÉÊ²Ã´£¿");
		return 0;
	}
	if(total*100>value) {
		command("say Ò½Ò©·ÑÒ»¹²ĞèÒª"+chinese_number(total)+"Á½°×Òø¡£");
		return 0;
	}
	message_vision(CYN "$NÌÍ³ö¼¸Ö§½ğÕë£¬´ÌÈë$nÈËÖĞ£¬Ó¡ÌÃ£¬×óÊÖÀÍ¹¬£¬ÓÒÏ¥×ãÈıÀïµÈÑ¨µÀ¡£\n" NOR, me, who);
	message_vision(CYN "Æ¬¿ÌÖ®ºó£¬$N½«½ğÕëÒ»Ò»°ÎÏÂ£¬\n$nÖ»¾õµÃÉ¤×ÓÑÛ·¢ÏÌ£¬ÕÅ×ìÍÂ³öÒ»¿ÚÎå²Ê°ßìµµÄÏÊÑª¡£\n" NOR, me, who);
	command("pat "+who->query("id"));
	command("say ²î²»¶àÁË¡£");
	for(i=0;i<sizeof(poisons);i++) {
                poison=poisons[i];
                duration=who->query_condition(poison["name"]);
                if(duration>0) {
			who->apply_condition(poison["name"], 0);
                }
        }
	who->set("eff_kee", who->query("max_kee"));
	who->set("eff_sen", who->query("max_sen"));
	return 1;
}

ÿ
