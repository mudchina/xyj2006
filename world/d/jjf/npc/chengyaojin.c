//cheng yaojin, updated 5/7/97, pickle
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string gloat();
string ask_me();

void create()
{
  set_name("³ÌÒ§½ğ", ({ "cheng yaojin", "cheng", "yaojin", "master", "shifu" }));
  set("title", "¿ª¹úÔªÑ«");
  set("gender", "ÄĞĞÔ");
  set("age", 45);
  set("str", 30);
  set("per", 10);
  set("cor", 70);
  set("cps", 15);
  set("long","
³ÌÒ§½ğÊÇ´óÌÆ¿ª¹ú³öÃûµÄ¸£½«£¬Ôø´ÓÃÎÖĞÑ§À´Ò»Ì×ÍşÃÍÎŞÆ¥µÄ
Ğû»¨Èı¸«£¬ºóÀ´ÓÖÔø°İµ¹¹ıÒ»Ãæ´óÆì¡£Ì¸ÆğËûµÄ¸£Æø£¬ÕæµÄÊÇ
ÈËÈËÏÛÄ½¡£
");
  set("combat_exp", 800000);
  set("daoxing", 200000);

  set_skill("unarmed", 100);
  set_skill("force", 90);
set_skill("lengquan-force", 120);
  set_skill("axe", 100);
set_skill("dodge", 100);
set_skill("parry", 110);
  set_skill("sanban-axe", 120);
set_skill("spells", 120);
set_skill("baguazhou", 120);
set_skill("yanxing-steps", 120);
  map_skill("force", "lengquan-force");
  map_skill("spells", "baguazhou");
  map_skill("axe", "sanban-axe");
  map_skill("parry", "sanban-axe");
  map_skill("dodge", "yanxing-steps");
  set_temp("apply/armor", 10);
  set("max_sen", 300);
  set("max_kee", 2800);
  set("force", 500); 
  set("max_force", 500);
  set("force_factor", 40);
  set("max_mana", 200);
  set("mana", 200);
  set("mana_factor", 10);
  set("inquiry", ([
	"name"     : "ÎÒ¾ÍÊÇÈË³Æ¸£½«µÄ³ÌÒ§½ğ£¡",
	"here"     : "ÕâÀïÊÇ´óÌÆ¹ú¶¼³¤°²¸®¡£",
	"rumors"   : "Äã¿´ÀÏ³ÌÏóÊÇ³ÉÌì³Ô±¥ÁË³ÅµÄ´òÌıĞ¡µÀÏûÏ¢µÄÃ´£¿",
	"¸£½«"     : (: gloat :),
	"°×·¢ÏÉÈË" : "ÄÇ°×·¢ÏÉÈËÊÇÎÒ¶÷Ê¦£¬ÈôÏë¼ûËû£¬ĞèµÃÓĞÔµ¡£",
	"ÓĞÔµ"     : (: ask_me :),
]) );

  create_family("½«¾ü¸®", 2, "À¶");

  setup();
  carry_object("/d/obj/weapon/axe/huafu")->wield();
  carry_object("/d/obj/armor/tongjia")->wear();
}

string gloat()
{
    command("say ºÙºÙ£¬ÌáÆğÕâ¸ö¿ÉÄÓµ½ÀÏ³ÌµÄÑ÷´¦ÁË£¡");
    command("say ÀÏ³Ì×îµÃÒâµÄ¾ÍÊÇµ±ÄêÄÇ°×·¢ÏÉÈËÃÎÖĞ´«ÎÒ¸«·¨¡£¡£¡£");
    return "ÄãÒªÊÇÏëÕ´×ÅµãÀÏ³ÌµÄ¸£Æø£¬¾ÍÓ¦¸Ã°İÎÒÎªÊ¦¡£";
}
string ask_me()
{
    command("hehe");
    command("say ºÎÎªÓĞÔµ£¿ÄãÈôÊÇÄÜ½Ó×¡ÀÏ³ÌÈı¸«²»ËÀ£¬¾ÍÊÇÓĞÔµÈË¡£");
    this_player()->add_temp("pending/jjf/to_be_hit", 1);
    return "Äã¿ÉÔ¸ÒâÒ»ÊÔ£¿(yuanyi)";
}

void init()
{
    ::init();

    add_action("do_agree", "yuanyi");
    add_action("do_agree", "agree");
}

int do_agree(string arg)
{
    object me=this_player(), npc=this_object(), ob;
    string myname=me->name(), myrude=RANK_D->query_rude(me);

    if (!me->query_temp("pending/jjf/to_be_hit"))
	return 0;
    me->delete_temp("pending/jjf/to_be_hit");
    set("force", 2*query("max_force"));
    set("force_factor", 200);
    if (!(ob=query_temp("weapon"))
     || ob->query_temp("skill_type") != "axe")
    {
	destruct(ob);
	ob=new("/d/obj/weapon/axe/huafu");
	ob->move(npc);
	command("wield axe");
    }
    command("say ¹ş¹ş£¬ÓĞµ¨×Ó£¡");
    COMBAT_D->do_attack(npc, me, query_temp("weapon"));
    if(me->query("kee") < 0
    || !present(me, environment()))
    {
	command("say ºÙºÙ£¬"+myrude+"Ò»¼Ò»ï¶¼¾­²»×¡£¬»¹ÊÇ»ØÈ¥¶àÁ·Á½Äê°É£¡");
	return 1;
    }
    command("say ²»´í£¬ÓĞµãÒâË¼£¬ÔÙ¿´ÕâÒ»ÕĞ£¡");
    COMBAT_D->do_attack(npc, me, query_temp("weapon"));
    if(me->query("kee") < 0
    || !present(me, environment()))
    {
	command("say "+myrude+"ÄÜ¾­×¡ÎÒÒ»ÏÂ×ÓÒÑ¾­²»ÈİÒ×ÁË£¬ÎÒÔç¾Í¿´³öÀ´ÕâµÚ¶şÏÂ×ÓÄãÊÜ²»ÁËÁË£¡");
	return 1;
    }
    command("say ¾ÓÈ»Í¦¹ıÁËÀÏ³ÌÁ½¼Ò»ï£¡");
    COMBAT_D->do_attack(npc, me, query_temp("weapon"));
    if(me->query("kee") < 0
    || !present(me, environment()))
    {
	command("say °¦£¬"+myrude+"µÄÔµ·İ±ÈÀÏ³ÌÒ²¾Í²îÁËÄÇÃ´Ò»¶¡µã¶ù¡£");
	return 1;
    }
    me->add_temp("jjf/°×·¢ÓĞÔµ", 1);
    command("say "+myname+"¹ûÈ»ÊÇÓĞÔµÈË¡£");
    command("say ÄãÈ¥ÕÒÎÒÊ¦¸¸°É£¡±ğÍüÁËËûÊÇ×Ô¼ºÀ´µ½ÎÒÃÎÖĞµÄ£¬ÕâÖÖ»ú»áÊÇ¿ÉÓö¶ø²»¿ÉÇó¡£");

    return 1;
}

int accept_fight(object me)
{
  command("say ÀÏ·ò¾ÃÎ´ºÍ½­ºşÈË¶¯ÊÖ¹ıÕĞÁË£¬½ñÈÕÒ²²»ÏëÆÆÀı¡£");
  return 0;
}

void attempt_apprentice(object me)
{
  int effstr=(int)(me->query("str"));
  int myuna=me->query_skill("unarmed", 1)/10-2;
  string myrude=RANK_D->query_rude(me);

  if (myuna < 0) myuna=0;
  effstr+=myuna;
  if (effstr<30)
    {
      command("say "+myrude+"Õâµã¾¢Á¬Ö»ÂìÒÏ¶¼Äó²»ËÀ£¬»¹ÄÜÂÕ¸«Í·£¿");
      return 0;
    }
  if (me->query_cor()<30)
    {
      command("say "+myrude+"¼ûÁËÑª£¬»¹²»µÃÏÅÆÆÁËµ¨¶ù£¿²»ÊÕ£¡");
      return 0;
    }
  command("ah");
  command("say Ïë²»µ½ÎÒÀÏ³ÌÕâÈı½ÅÃ¨±¾ÊÂÒ²ÄÜÊÕÍ½¡£\n");
  command("recruit " + me->query("id") );
message("system", HIR"³ÌÒ§½ğ£º"HIY"´óÌÆ½«¾ü¸®ÓÖ¶àÁËÒ»¸öµÜ×Ó"+this_player()->name()+HIW"

                          ´óÌÆ½«¾ü¸®µÄÊÆÁ¦¼ÓÇ¿ÁË¡£\n"NOR,users());
  return;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "fighter");
}
int prevent_learn(object me, string skill)
{
  if (skill =="spells" || skill == "baguazhou")
    {
      command("say ÀÏ·ò×Ô¼ºÒ²¸ã²»Çå³şÔõÃ´»ØÊÂ£¬ÄÄÀïÄÜ½ÌÄãÄØ£¿");
//      return notify_fail("¿´À´´Ó³ÌÒ§½ğÕâÀïÑ§²»µ½ÕâÏî±¾ÁìÁË¡£");
      return 1;
    }
  return 0;
}
ÿ
