inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
  set_name("³¤ÍÈÏº±ø", ({"changtui xiabing","xiabing"}));
  set("gender", "ÄĞĞÔ");
  set("age", 25);
  set("title", "±Ì²¨Ì¶¾ÅÍ·æâÂíÊÌÎÀ");
  set("long","±Ì²¨Ì¶ÓëÁú¹¬ºÍ»ğÔÆ¶´¶¼ÓĞ½»Çé,ËûÊÇÀ´Áú¹¬×ö¿ÍµÄ,Ë³±ãÒ²ÊÕĞ©Í½µÜ¡£\n");
  set("combat_exp", 100000+random(3000));
  set("daoxing", 100000);
  set("per", 15);
  set_skill("dodge", 70);
  set_skill("parry", 70);
  set_skill("unarmed", 70);
  set_skill("force", 70);
  set_skill("spells", 70);
  set_skill("fork", 70);
  set_skill("huaxue-dafa", 70);
  set_skill("huaxue-force", 70);
  set_skill("moyun-shou", 70);
  set_skill("moshenbu", 70);
  map_skill("force", "huaxue-force");
  map_skill("spells", "huaxue-dafa");
  map_skill("unarmed", "moyun-shou");
  map_skill("dodge", "moshenbu");
  map_skill("fork", "yueya-chan");
  set("max_sen",800);
  set("max_kee",800);
  set("force", 400);
  set("max_force", 400);
  set("force_factor", 20);
  set("mana", 400);
  set("max_mana", 400);
  set("mana_factor", 20);

        set("inquiry", ([
                "ÏÂÉ½": (: expell_me :),
                "leave": (: expell_me :),
]) );

  create_family("±Ì²¨Ì¶", 3, "À¶");

  setup();

  carry_object("/d/qujing/kusong/obj/tongjia")->wear();
  carry_object("d/obj/weapon/stick/mugun")->wield();


}

void attempt_apprentice(object ob)
{       ob=this_player();

        if( (string)ob->query("family/family_name") == "±Ì²¨Ì¶") {
		command("say ´ó¼ÒÍ¬ÃÅÖĞÈË£¬²»¸Òµ±£¬²»¸Òµ±£¡\n");
		return;
	}
                command("grin");
                command("recruit " + ob->query("id"));
                return ;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "yaomo");
                ob->set("title", "ÂÒÊ¯É½±Ì²¨Ì¶Ğ¡Ñı");
        }
}

string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="±Ì²¨Ì¶") {
                me->set_temp("betray", 1);
                return ("ÄãÕæµÄÒªÀë¿ªÂğ?ÄãÒª¸¶³öÒ»Ğ©´ú¼Û,Äã¿ÉÔ¸Òâ(agree)?");
        }
        return ("²»Öª¡£");
}
void init()
{
::init();
        add_action("do_agree", "agree");
}

int do_agree(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N´ğµÀ£ºÔ¸Òâ¡£\n\n", this_player());
                this_player()->add("betray/count", 1);
                this_player()->add("betray/bibotan", 1);
		this_player()->set("combat_exp", this_player()->query("combat_exp")*95/100);
                            if( this_player()->query_skill("huaxue-force") )
		  this_player()->delete_skill("huaxue-force");
                if( this_player()->query_skill("huaxue-dafa") )
		   this_player()->delete_skill("huaxue-dafa");
                            this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "ÆÕÍ¨°ÙĞÕ");
                this_player()->save();
                command("say ÄÇÄãÈ¥°É£¡\n");
                return 1;
                }
        return 0;
}

ÿ