//Cracked by Roath
inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
  set_name("¼±Èç»ğ", ({"jiru huo","huo"}));
  set("gender", "ÄĞĞÔ");
  set("age", 10);
  set("title", "»ğÔÆ¶´½¡½«");
  set("long","Ò»¸öÔôÃ¼ÊóÑÛµÄĞ¡Ñı¾«¡£\n");
  set("combat_exp", 100000+random(3000));
  set("daoxing", 100000);

  set("per", 15);

  set_skill("dodge", 60);
  set_skill("parry", 60);
  set_skill("unarmed", 60);
  set_skill("force", 60);
  set_skill("spells", 60);
  set_skill("pingtian-dafa", 40);
  set_skill("huomoforce", 40);
  set_skill("moyun-shou", 40);
  set_skill("moshenbu", 40);
  set_skill("fork", 60);
  set_skill("spear", 60);
  set_skill("stick", 60);
   set_skill("dali-bang",60);
  map_skill("force", "huomoforce");
  map_skill("spells", "pingtian-dafa");
  map_skill("unarmed", "moyun-shou");
  map_skill("dodge", "moshenbu");

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

  create_family("»ğÔÆ¶´", 3, "À¶");

  setup();

  carry_object("/d/qujing/kusong/obj/tongjia")->wear();
}

void attempt_apprentice(object ob)
{       ob=this_player();

        if( (string)ob->query("family/family_name") == "»ğÔÆ¶´") {
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
                ob->set("title", "¿İËÉ½§»ğÔÆ¶´Ğ¡Ñı");
        }
}

string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="»ğÔÆ¶´") {
                me->set_temp("betray", "1");
                return ("¼ÈÊÇÒª³öÉ½£¬È´ĞèÊÜÉ½¹æ³Í·££¬Äã¿ÉÔ¸Òâ(agree)?");
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
      if(this_player()->query_temp("betray") &&
                  this_player()->query("family/family_name")=="»ğÔÆ¶´") {
                message_vision("$N´ğµÀ£ºÔ¸Òâ¡£\n\n", this_player());
                this_player()->add("betray/count", 1);
                this_player()->add("betray/huoyun", 1);
this_player()->set("combat_exp",this_player()->query("combat_exp")/5*4);
this_player()->set("daoxing",this_player()->query("daoxing")/5*4);
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
