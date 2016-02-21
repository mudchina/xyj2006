//Cracked by Roath
 
#include <ansi.h>
inherit NPC;

int buy_jiasha(object me);
int ask_qujing(object me);
int so_gui(object me);
int hao_bu_hao(object me);
int buyao_qian(object me);
void create()
{
   set_name("疥癞和尚", ({ "jielai heshang", "heshang", "bonze" }));
   set("long", @LONG
疥癫形容，身穿破袖，赤脚光头。
LONG);
   set("gender", "男性");
   set("age", 35);
   set("title", "疯疯癫癫");
   set("attitude", "peaceful");
   set("rank_info/self", "贫僧");
   set("class", "bonze");
           set("str",24);
   set("per",100);//means no rong-mao description.
   set("max_kee", 5000);
   set("max_gin", 5000);
   set("max_sen", 5000);
   set("force", 4000);
   set("max_force", 2000);
   set("force_factor", 145);
   set("max_mana", 3000);
   set("mana", 6000);
   set("mana_factor", 150);
   set("combat_exp", 2000000);
   set_skill("literate", 150);
   set_skill("spells", 200);
   set_skill("buddhism", 200);
   set_skill("unarmed", 150);
   set_skill("jienan-zhi", 150);
   set_skill("dodge", 180);
   set_skill("lotusmove", 160);
   set_skill("parry", 150);
   set_skill("force", 180);
   set_skill("lotusforce", 180);
   set_skill("staff", 150);
   set_skill("lunhui-zhang", 180);
   set_skill("spear", 150);
   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("force", "lotusforce");
   map_skill("parry", "lunhui-zhang");
   map_skill("staff", "lunhui-zhang");
   set("chat_chance_combat", 80);
   set("chat_msg_combat", ({
     (: cast_spell, "bighammer" :),
     (: cast_spell, "jinguzhou" :)
   }) );
	     set("chat_chance", 20);
	     set("chat_msg", ({
	       "疥癞和尚大声地说道：我有一件[示阑]禅异宝袈裟，\n"
               "疥癞和尚大声地喊道：贫僧想卖这件袈裟。\n",
               "疥癞和尚大声地叫道：我这袈裟，龙披一缕，免大鹏吞噬之灾；鹤挂一丝，得超凡入圣之妙。但坐处，有万神朝礼；凡举动，有七佛随身。\n",
               "疥癞和尚大声地说道：我这袈裟是冰蚕造练抽丝，巧匠翻腾为线。仙娥织就，神女机成，方方簇幅绣花缝，片片相帮堆锦筘。玲珑散碎斗妆花，色亮飘光喷宝艳。\n",
               "疥癞和尚大声地说道：穿上我这袈裟满身红雾绕，脱来一段彩云飞。三天门外透玄光，五岳山前生宝气。重重嵌就西番莲，灼灼悬珠星斗象。\n",
               "疥癞和尚大声地叫道：我这袈裟四角上有夜明珠，攒顶间一颗祖母绿。虽无全照原本体，也有生光八宝攒。\n",
               "疥癞和尚大声地说道：这袈裟，闲时折叠，遇圣才穿。闲时折叠，千层包裹透虹霓；遇圣才穿，惊动诸天神鬼怕。\n",
               "疥癞和尚大声地说道：我这袈裟上边有如意珠，摩尼珠，辟尘珠，定风珠；又有那红玛瑙，紫珊瑚，夜明珠，舍利子。偷月沁白，与日争红。\n",
               "疥癞和尚大声地说道：条条仙气盈空，朵朵祥光捧圣。条条仙气盈空，照彻了天关；朵朵样光捧圣，影遍了世界。照山川，惊虎豹；影海岛，动鱼龙。\n",
               "疥癞和尚大声地说道：沿边两道销金锁，叩领连环白玉珠。诗曰；三宝巍巍道可尊，四生六道尽评论。明心解养人天法，见性能传智慧灯。\n",
               "疥癞和尚大声地说道：护体庄严金世界，身心清净玉壶冰。自从佛制袈裟后，万劫谁能敢断僧？”\n",
                (: random_move :)
        }));
        set("inquiry", ([
	"买袈裟": (: buy_jiasha :),
        "取经": (: ask_qujing :),
        "这么贵":(:so_gui :),
        "好与不好":(:hao_bu_hao :),
        "不要钱":(:buyao_qian :),
        ]) );



   setup();
carry_object("/d/obj/weapon/staff/gangzhang")->wield();
   carry_object("/d/nanhai/obj/sengpao")->wear();
   carry_object("/d/nanhai/obj/nine-ring")->wield();
}
void init()
{
        object ob=this_object();
	object me=this_player();
	::init();
	add_action("do_kill", "kill");
	if (! interactive(me))
	return;
	if( (int)me->query("eff_kee") < (int)me->query("max_kee")*3/4 )
   	
	switch (random(2))
	  {
    	case 0:
    	{	
	command("say 这位"+ me->query("rank_info/respect")+"气色不太好，我来给你看看！\n");
	command("exert lifeheal "+me->query("id") );
	command("exert recover");
	}
	break;
	case 1:
	{
	command("pat "+ me->query("id"));
	command("say 这位"+ me->query("rank_info/respect")+"要注意身体哦！\n");
	}
	break;
	}

	if( me->is_fighting() )
	{
	command("sigh" + me->query("id"));
	message_vision(HIY"$N对着$n叹道：渊渊相报，何时了啊！这位"+me->query("rank_info/respect")+
		"听我一句，放下屠刀，立地成佛！\n"NOR,ob,me);
	message_vision(HIY"$N听罢，真个不再打下去了。\n"NOR,me);
	me->remove_all_killer();	
	}
}
int so_gui(object me)
{
	message_vision(HIY"袈裟有好处，有不好处；有要钱处，有不要钱处。\n"NOR,me);
	return 1;
}	            
int hao_bu_hao(object me)
{
	message_vision(HIY"看了我袈裟，不久沉沦，不堕地狱，不遭恶毒之难，不遇虎狼之灾，便是好处,\n"NOR,me);
	message_vision(HIY"若贪淫乐祸的愚僧，不斋不戒的和尚，毁经谤佛的凡夫，难见我袈裟之面，这便是不好处。\n"NOR,me);
	return 1;
}	            
int buyao_qian(object me)
{
	message_vision(HIY"不遵佛法，不敬三宝，强买袈裟，定要卖他五千两，这便是要钱,\n"NOR,me);
	message_vision(HIY"若敬重三宝，见善随喜，皈依我佛，承受得起，我将袈裟情愿送他，与我结个善缘，这便是不要钱。\n"NOR,me);
	return 1;
}	            
int buy_jiasha(object me)
{
	message_vision(HIY"我这件袈裟卖五千两黄金。\n"NOR,me);
	return 1;
}	            

int ask_qujing(object me)
{       
	
	object jiasha=new("/d/obj/cloth/jiasha2");
	me=this_player();
	if( me->query("obstacle/jz") != "done") 
	return notify_fail("取经？你是取经人吗？\n");
		message_vision(HIY"哈哈，果然是求取真经的人。\n"NOR, me);
                message_vision(HIY"这就将五彩袈裟赐给你，望你早日取回真经。\n"NOR, me);
                jiasha->move(me);
		message_vision(HIW"$N给$n一件"+jiasha->name()+"。\n"NOR, this_object(), me);
		message_vision(HIW"和尚现出菩萨的真身，坐在一朵莲花上，消失在空中"NOR,me);
                message_vision(HIW"你不由向天膜拜，恭送菩萨离去。\n"NOR,me);         
		destruct(this_object());
		return 1;
}
int do_kill(string arg)
{
  object me = this_player();
  object ob = this_object();

  if (arg)
  {
	message_vision(HIY"$N对着$n叹道：渊渊相报，何时了啊！这位"+me->query("rank_info/respect")+
			"听我一句，放下屠刀，立地成佛！\n"NOR,ob,me);
	message_vision(HIY"$N听罢，真个不再打下去了。\n"NOR,me);
    return 1;
  }
  return 0;
}

