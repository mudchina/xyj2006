#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int give_me(object ob);
int delete_ask(object ob);
int create_pai(object ob);

void create()
{
       set_name("鲸无敌", ({"jing wudi", "jing"}));

set("long","身高八丈，膀大腰圆．号称东海第一勇士。
水族需有他发的腰牌才能自由出入于水晶宫中。\n");
       set("gender", "男性");
       set("age", 56);
        set("title", "将军");
        set("per", 10);
        set("str", 1000);
	set("con", 30);
	set("int", 20);
        set("max_kee", 1500);
	set("max_sen", 1000);
       set("attitude", "heroism");
       set("combat_exp", 700000);
  set("daoxing", 200000);

       set_skill("unarmed",100);
       set_skill("dodge",100);
	set_skill("hammer", 150);
	set_skill("parry", 150);
	set_skill("force", 100);
	set_skill("spells", 100);
	set_skill("seashentong", 50);
	set_skill("dragonforce", 50);
	set_skill("dragonstep", 50);
	set_skill("literate", 50);
	set_skill("dragonfight", 50);
	map_skill("unarmed", "dragonfight");
	set_skill("huntian-hammer", 150);
	map_skill("hammer", "huntian-hammer");
	map_skill("parry", "huntian-hammer");
	map_skill("force", "dragonforce");
	map_skill("dodge", "dragonstep");
	map_skill("spells", "seashentong");
	set("force", 800);
	set("max_force", 800);
	set("force_factor", 40);
	set("mana", 800);
	set("max_mana", 800);
	set("mana_factor", 40);
	set("have", 3);

    create_family("东海龙宫", 2, "水族");
        set("inquiry", ([
                "腰牌": (: give_me :),
                "pai": (: give_me :),
        ]) );

       setup();
       carry_object("/d/ourhome/obj/ironarmor")->wear();
       carry_object("/d/obj/weapon/hammer/bahammer")->wield();
	carry_object("/d/sea/obj/pai");
        remove_call_out("create_pai");
        call_out("create_pai",920,this_object());
}

void attempt_apprentice(object ob)
{
        command("look "+ ob->query("id"));
	command("nod");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dragon");
}

int give_me(object ob)
{
	object who, me,pai;
	who=this_player();
	me=this_object();
	pai=new("/d/sea/obj/pai");

	if( (string)who->query("family/family_name")!="东海龙宫" ) {
		if( (int)who->query_temp("pending/ask_time") >= 3) {
			message_vision("$N突然跳起，恶狠狠的瞪着$n说：看来你是不想活了！\n", me, who);
			command("kill " + who->query("id"));
			return 1;
			}
		message_vision("$N斜斜地瞟了$n一眼，说：此不足为外人道也！\n", me, who);
		who->add_temp("pending/ask_time", 1);
		return 1;
	}     
       else {

	if( (int)who->query("combat_exp")+(int)who->query("daoxing") < 300 ) {
		command("baobao " +who->query("id"));
		return 1;
	}
        if( (int)who->query("faith")< 500 ) {
                message_vision("$N很疑惑地看着你说到：你新来的吧?我似乎没见过你。\n",me);
                return 1;
           }
       if( (int)who->query("jing_time")>time() )
           {
             message_vision("$N摇了摇头：你刚才不是已经要过了吗？\n",me);
             return 1;
            }
       if(objectp(present("yao pai",who)))
           {
           	message_vision("$N很疑惑地看着你说到：你身上不是已经有了吗。\n",me);
           	return 1;
           }
	if( (int)me->query("have") ){
		command("nod "+who->query("id"));
		message_vision(CYN"$N拿出一只腰牌给$n。\n"NOR,me,who);
		me->add("have", -1);
		pai->set("obj_owner",who->query("id"));
		pai->move(who);
	
		who->add_temp("pending/ask_time", 1);
                who->set("jing_time",time()+300);
              
		return 1;
		}
	}
	message_vision("$N对$n无奈的一伸手，说：今日腰牌已发完了，明日再来领吧。\n", me, who);
	return 1;
}


int create_pai(object ob)
{
	ob->set("have",3);
        remove_call_out("create_pai");
        call_out("create_pai",920,ob);	
	return 1;
}
