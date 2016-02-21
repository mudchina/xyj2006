// worker.c

inherit NPC;
void create()
{
        set_name("¿³²ñµÀÊ¿", ({ "taoist", "dao shi", "dao" }) );
        set("gender", "ÄÐÐÔ" );
        set("age", 35);
	set("per", 30);
	set("class", "taoist");
        set("long", "Ò»Î»µÀ³¤£¬ÏëÊÇÉ½ÖÐµÀ¹ÛÀïµÄ¡£\n");
        set("combat_exp", 10000);
  set("daoxing", 20000);

        set("attitude", "peaceful");
	set_skill("axe", 10);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_skill("unarmed", 20);
  	set("chat_chance",5);
  	set("chat_msg",({
        "Ö»Ìý¿³²ñµÀÊ¿³ªµÀ£ºÔÆ¼ÊÒÀÒÀÈÏ¾ÉÁÖ£¬¶ÏÑÂ»Ä²ÝÂ·ÄÑÑ°¡£\n",
        "¿³²ñµÀÊ¿³ªµÀ£ºÎ÷É½Íû¼û³¯À´Óê£¬ÄÏ½§¹éÊ±¶É´¦Éî¡£\n",
	"¿³²ñµÀÊ¿³ªµÀ£º¹ÛÆå¿ÂÀÃ£¬·¥Ä¾¶¡¶¡£¬ÔÆ±ß¹È¿ÚÐìÐÐ£¬ÂôÐ½¹Á¾Æ£¬¿ñÐ¦×ÔÌÕÇé¡£\n",
	"¿³²ñµÀÊ¿µÍÉù³ªµÀ£ºÏà·ê´¦£¬·ÇÏÉ¼´µÀ£¬¾²×ø½²»ÆÍ¥¡£\n",
    	}));

        setup();
        add_money("coin", 50);
        carry_object("/d/lingtai/obj/axe")->wield();
}
int accept_fight(object me)
{       me=this_player();
        if((int)this_player()->query("combat_exp") < 30000) {
        this_object()->set("combat_exp", (int)this_player()->query("combat_exp")+500);
        }
        return 1;
}

ÿ