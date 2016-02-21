#include <ansi.h>
inherit NPC;
int handle_kill(object me);

void create()
{
        set_name("二郎真君", ({"erlang zhenjun", "erlang", "zhenjun"}));
        set("long", "他是赤城昭惠英灵圣，显化无边号二郎。
力伏八怪声名远，义结梅山七圣行。\n");
	set("looking", "仪容清俊貌堂堂，两耳垂肩目有光。");
        set("age", 28);
        set("attitude", "peaceful");
        set("gender", "男性");
        set("title", "昭惠灵显王");
        set("str", 40);
        set("int", 40);
        set("per", 30);
	set("con", 30);
       set("max_kee",8000);
        set("max_sen", 8000);
        set("combat_exp", 15000000);
        set("daoxing", 20000000);

        set("force", 8000);
        set("max_force", 8000);
        set("mana", 16000);
        set("max_mana", 8000);
        set("force_factor", 200);
        set("mana_factor", 200);

        set("eff_dx", 800000);
        set("nkgain", 800);

        set_skill("unarmed", 350);
	set_skill("force", 350);
	set_skill("spells", 350);
       set_skill("parry", 450);
       set_skill("dodge", 450);
       set_skill("spear", 450);
       set_skill("dao",350);
       set_skill("huomoforce",350);
	set_skill("moyun-shou", 350);
	set_skill("moshenbu", 450);
       set_skill("bawang-qiang", 450);
       set_skill("mace", 350);
       set_skill("wusi-mace", 350);
       map_skill("mace","wusi-mace");  
	map_skill("unarmed", "moyun-shou");
	map_skill("dodge", "moshenbu");
       map_skill("spear","bawang-qiang");
       map_skill("parry", "bawang-qiang");
       map_skill("force","huomoforce");
       map_skill("spells","dao");
       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
                  (: perform_action, "unarmed", "zhangxinlei" :), 
       }) );
       set("inquiry", ([ /* sizeof() == 4 */
  		"here" : "我奉佛祖谕旨，正要捉拿青霞，紫霞二人。",
  		"name" : "我乃二郎神杨戬是也。",
	]) );

        setup();
        carry_object("/d/meishan/npc/obj/spear")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
        carry_object("/d/obj/drug/jinchuang")->set_amount(random(10));
}

void init()
{
	object me=this_object();
	object who=this_player();

	add_action("do_kill", "kill");
	return ::init();
}
		     
void die()
{
	int dx,dx1,wx,qn;
	object who;
	object me=this_object();
    who=present(me->query("killer"),environment());
if (!who) return 0;
	dx=(who->query("daoxing"))/20;
if (dx>=100000) dx=100000;
	dx1=dx/1000;
	wx=(who->query("combat_exp"))/20;
if (wx>=10000) wx=10000;
	qn=30000;
    
  	if (!who->query_temp("give_suo"))
	  return ::die();
   if ((!present("qingxia xianzi"))&&(!present("zixia xianzi")))
	{
	   who->delete("fangcun/panlong_nowaypansi");
	   return ::die();
	}
   message("sound", "\n\n\n二郎神怒道：你莫要猖狂，待我到如来佛祖那里告状去！\n",environment());
   message("sound", "\n二郎神搭上白云，往西天灵山飞去。。。\n\n",environment());
   if (present("xiaotian quan"))
  {    
     message("sound", "啸天犬也跟着二郎神往西逃去．\n\n", environment());
     destruct(present("xiaotian quan"));
  }
   message_vision(WHT"\n\n青霞看着受了重伤的紫霞，紧紧的握着紫霞的手哽咽着说道：\n"NOR, who);
   message_vision(WHT"\n           我也只有你这么一个妹妹，我们不要再斗下去了．二郎神已经去佛祖那里告状去
        了，我们也该回到佛祖那里继续作灯芯了，若是走晚了还要连累"+RANK_D->query_respect(who) + "被佛祖责怪．\n"NOR, who);
   message_vision(HIM"\n\n\n紫霞也紧紧的握着青霞的手止不住的泪水已经流了下来：\n"NOR, who);
   message_vision(HIM"\n           这尘事已经没有什么可留恋的了，姐姐，我们走．\n\n\n"NOR, who);
   message_vision("\n青霞搀着重伤的紫霞，两人对着$N再三拜谢后驾起云头往西天灵山去了．\n"NOR, who);
   message_vision(HIY"\n\n\n$N仰天还礼，目送二人渐渐远去，一阵说不出的滋味涌上心头．．．．．．\n"NOR, who);
   destruct(present("qingxia xianzi"));
   destruct(present("zixia xianzi"));
   message_vision(HIM"\n\n\n天边隐隐传来紫霞的声音："+who->query("name")+RANK_D->query_respect(who) + "灵台观礼之事，恕我不能前往道贺，望" + RANK_D->query_respect(who) + "代我向尊师菩提请罪了．\n\n\n\n"NOR,who);
		who->add("fangcun/panlong_visite",1);
		who->set("fangcun/panlong_pansi","done");
		who->delete("fangcun/panlong_nowaypansi");
 message("chat",HIC+"〖"+HIW+"西游记2006"+HIC+"〗如来佛祖(Rulai fo)："+who->query("name")+"助紫青二仙了却千年怨恨，皈依我佛，当真功德无量也．\n"NOR,users());
        message("chat",HIC+"〖"+HIW+"西游记2006"+HIC+"〗如来佛祖(Rulai fo)："+who->query("name")+"得到奖励：道行"+chinese_number(dx1)+"年，武学"+wx+"点，潜能30000点．\n"NOR,users());
	who->add("daoxing",dx);
	who->add("combat_exp",wx);
	who->add("potential",30000);
	    if ((me->query("family/family_name")!="方寸山三星洞")||(me->query("fangcun/panlong_noway")))
		who->set("guanli/pansi",1);
   destruct(this_object());
   return;
}

void unconcious()
{
 call_out("die",1);
}

int do_kill(string arg)
{
    if(!id(arg)) return 0;
    handle_kill(this_player());
    return 0;
}
int handle_kill(object me)
{
    if (me->query("fangcun/panlong_nowaypansi"))
  {
	  set_skill("unarmed", 200);
	set_skill("force", 200);
	set_skill("spells", 200);
       set_skill("parry", 200);
       set_skill("dodge", 200);
       set_skill("spear", 200);
       set_skill("dao",200);
       set_skill("huomoforce",200);
	set_skill("moyun-shou", 200);
	set_skill("moshenbu", 200);
       set_skill("bawang-qiang", 200);
       set_skill("mace", 200);
       set_skill("wusi-mace", 200);
       set("force_factor", 1);
        set("combat_exp", 1500000);
        set("daoxing", 3000000);
        set("mana", 4000);
        set("max_mana", 5000);
	   this_object()->set("killer",me->query("id"));
  }
}

