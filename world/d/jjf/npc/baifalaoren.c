// lao ren, 2001,lestat

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string kick_back();
int begin_go();

void create()
{
  set_name(HIW"°×·¢ÀÏÈË"NOR, ({ "lao ren", "lao", "laoren","ren", "baifa", "immortal", "master", "shifu" }));

  set("gender", "ÄĞĞÔ");
  set("age", 100);

  set("str", 20);
  set("per", 130);
  set("cor", 30);
  set("cps", 75);
  set("kar", 100);
  set("int", 40);
  set("con", 40);
  set("spi", 40);

  set("long","
ÕâÊÇÒ»Î»º×·¢Í¯ÑÕµÄÀÏÈË¡£Ëû¿´ÆğÀ´ËÆºõºÜÀÏµÄÑù×Ó£¬
µ«Æ«ÓÖÊÇºì¹âÂúÃæ¡£¿´µ½Äã´òÁ¿Ëû£¬Ëû¶ÔÄãºÍ°ªµØĞ¦ÁË
Ò»Ğ¦¡£

");
  set("title", HIY"ÉñÏÉ"NOR);
  set("combat_exp", 2000000);
  set("daoxing", 2000000);


  set_skill("literate", 200);
  set_skill("unarmed", 180);
  set_skill("force", 180);
  set_skill("lengquan-force", 180);
  set_skill("axe", 180);
  set_skill("dodge", 180);
  set_skill("parry", 180);
  set_skill("sanban-axe", 180);
  set_skill("bawang-qiang", 180);
  set_skill("spells", 180);
  set_skill("baguazhou", 180);
  set_skill("mace", 180);
  set_skill("spear", 200);
  set_skill("yanxing-steps", 180);
  map_skill("force", "lengquan-force");
  map_skill("spells", "baguazhou");
  map_skill("axe", "sanban-axe");
  map_skill("parry", "sanban-axe");
  map_skill("dodge", "yanxing-steps");
  map_skill("spear", "bawang-qiang");

  set("max_sen", 4500);
  set("max_kee", 3500);
  set("force", 1500); 
  set("max_force", 2500);
  set("force_factor", 140);
  set("max_mana", 3000);
  set("mana", 3000);
  set("mana_factor", 150);

  set("inquiry", ([
	"name"    : "ÎÒÊÇË­£¿ÎÒÒ²²»¼ÇµÃÁË¡£",
	"here"    : "ÕâÊÇÒ»³¡ÃÎ¡£",
	"rumors"  : "ÏûÏ¢£¿Äã²»×¨ĞÄÑ§ÒÕ£¬ÓÖÀ´´òÌıÊ²Ã´ÏûÏ¢£¿",
	"»ØÈ¥"    : (: kick_back :),
	"return"  : (: kick_back :),
    "ÁéÌ¨¹ÛÀñ"    : (: begin_go :),
]) );

  create_family("½«¾ü¸®", 1, "À¶");

  setup();
  carry_object("/d/obj/weapon/axe/huafu")->wield();
  carry_object("/d/obj/cloth/linen")->wear();
}

int begin_go()
{
	object me,ob;
	me=this_player();
	ob=this_object();
	if (!me->query_temp("baifalaoren"))
	{
		command("say ÀÏ·ò½üÈÕÀ´²»Ô¸³öÓÎ£®\n");
		return 1;
	}
   command("say " + RANK_D->query_respect(me) + "ÓëÀÏ·òÉõÊÇÓĞÔµ£¬¼ÈÈ»Ç××ÔÀ´Çë£¬ÄÇÁéÌ¨¹ÛÀñÀÏ·òÕâ¾ÍÍ¬" + RANK_D->query_respect(me) + "È¥¿´¿´¡£");
   me->set("fangcun/panlong_jjf","done");
   me->move("/d/lingtai/inside1");
   ob->move("/d/lingtai/inside1");
   message_vision("\n$NÖ»¾õµÃÒ»µÀ°×¹âÒ»ÉÁ£¬Õû¸öÈË±ãËæ°×·¢ÀÏÈËÒ»Í¬À´µ½ÁËÁíÍâÒ»¸öµØ·½£®\n"NOR,me);
   return 1;
}

string kick_back()
{
    object me=this_player();

    message_vision(CYN"$nÌ§ÊÖ³¯$NµÄÇ°¶îÃÍµÄÒ»ÅÄ£¬ºÈÉù¡¸È¥£¡¡¹\n"NOR, me, this_object());
    message_vision(CYN"$NµÄÉíÓ°½¥½¥µ­È¥ÁË£®£®£®\n"NOR, me);
    me->move("/d/jjf/guest_bedroom");
    message_vision("$NÍ»È»¾ªĞÑ×øÆğ£¬Ô­À´ÊÇÄÏ¿ÂÒ»ÃÎ£®£®£®\n", me);
    return "";
}
int accept_fight(object me)
{
  command("say °¦£¬ÄêÇáÈË£¬»ğÆø¾ÍÊÇ´ó¡£±ğ¶¯´Ö±ğ¶¯´Ö£¡");
  return 0;
}

void attempt_apprentice(object me)
{
  int effstr=(int)(me->query("str")+me->query_skill("unarmed",1)/10-2);
  string myrespect=RANK_D->query_respect(me);

  if (wizardp(me) && me->query("env/override"))
  {
	command("recruit "+me->query("id"));
	return;
  }
  if (me->query("family/master_id") != "cheng yaojin"
   || !me->query_temp("jjf/°×·¢ÓĞÔµ"))
  {
	command("say Õâ¡£¡£¡£ÀÏ·òËØÀ´²»ÊÕÎŞÔµÖ®ÈË£¬"+myrespect+"»¹ÊÇ»ØÈ¥°É¡£");
	return;
  }
  if (effstr<30)
  {
      command("say "+myrespect+"µÄ±ÛÁ¦µÍÁËĞ©£¬¿ÖÅÂÄÑÒÔÑ§¸«¡£");
      return;
  }
  command("nod");
  command("say ¿´À´"+myrespect+"ÓëÎÒÓĞÔµ£¬ÀÏ·ò¾ÍÊÕÏÂÄã°É£¡\n");
  command("recruit " + me->query("id") );
  return;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "fighter");
}
ÿ
