// bishu.c ±ÌÊó¾«
// 9-2-97 pickle

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

/************************************************************/

// function and global variable declaractions

int attempt_apprentice(object me);
int recruit_apprentice(object me);
int prevent_learn(object me, string skill);
int accept_object(object me, object ob);
void bishu_leave(object me);
/************************************************************/

void create()
{
  set_name("±ÌÊó¾«", ({"bi shu", "bi", "shu", "bishu", "monster"}));
  set("gender", "Å®ĞÔ");
  set("age", 19);
  set("long",
"ËäÈ»Ëı¿´ÆğÀ´Èõ²»½û·ç£¬µ«ÌıËµËıÌì¸³¼°¼Ñ£¬ÊÇ¿éĞŞÏÉµÄºÃÁÏ×Ó¡£\n"
"×Ô´ÓÈëÎŞµ×¶´ÒÔÀ´£¬ËıµÄÎä¹¦½ø²½¼°¿ì£¬ÆÄÓĞ¸Ï¹ıÓñÊóµÄ¼ÜÊ½¡£\n");
  set("title", "ÎŞµ×¶´´óµÜ×Ó");
  set("nickname", HIR"¾ÅËÀÒ»Éú"NOR);
  set("combat_exp", 800000);
  set("daoxing", 1500000);

  set("attitude", "heroic");
  create_family("Ïİ¿ÕÉ½ÎŞµ×¶´", 2, "µÜ×Ó");
  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set_skill("stealing", 300);
  set_skill("spells", 100);
  set_skill("sword", 30);
  set_skill("qixiu-jian", 30);
  set_skill("yinfeng-zhua", 30);
  set_skill("lingfu-steps", 100);
  set_skill("force", 100);
  set_skill("blade", 100);
  set_skill("kugu-blade", 100);
  set_skill("yaofa", 30);
  set_skill("huntian-qigong", 30);
  map_skill("force", "huntian-qigong");
  map_skill("blade", "kugu-blade");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("spells", "yaofa");
  map_skill("sword", "qixiu-jian");
  map_skill("parry", "qixiu-jian");
  map_skill("dodge", "lingfu-steps");
  
  set("cor", 50);
  set("str", 30);
  set("per", 30);
  set("max_kee", 900);
  set("max_sen", 900);
  set("force", 650);
  set("max_force", 650);
  set("force_factor", 20);
  set("mana", 650);
  set("max_mana", 600);
  set("mana_factor", 25);
  set("inquiry", ([
                   "name": "±¾¹ÃÄï¾ÍÊÇµØÓ¿·òÈËµÄ¿ªÉ½´óµÜ×Ó£¡",
                   "here": "ÄãÏ¹ÁËÑÛÀ²£¿ÕâÀï¾ÍÊÇ¶¦¶¦´óÃûµÄÏİ¿ÕÉ½ÎŞµ×¶´£¡",
		   "rumors": "²»ÖªµÀ£¡ÕÒ±ğÈËÎÊÈ¥¡£",
		   "ÈËÈâ°ü×Ó": "ÄãÏ¹ÁËÑÛÀ²£¿±¾¹ÃÄïÓÖ²»ÊÇ³ø×Ó£¡",
                 ]) );  

  setup();
  carry_object("/d/obj/weapon/blade/blade.c")->wield();
  carry_object("/d/obj/cloth/nichang")->wear();
}
int attempt_apprentice(object me)
{
  string myname=RANK_D->query_rude(me);
  string myid=me->query("id");
  command("look "+myid);
  command("consider");
  if (me->query("combat_exp")+me->query("daoxing")<200000)
  {
    command("say "+myname+"ÓĞÊ²Ã´ÓÃ£¿¾ÍÕâÃ´µã±¾ÊÂ»¹²»¹»¸ø±¾¹ÃÄïÌáĞ¬£¡");
    return 1;
  }
  if (me->query("wudidong/sell_reward") < 5000)
  {
    command("say "+myname+"¶à¾ÃÃ»¸ø³ø·¿½ø»õÁË£¿£¡±¾¹ÃÄïµÈÈËÈâ°ü×Ó¶¼µÈ·³ÁË£¡");
    command("say ÏÈÈ¥¸ø³ø·¿ËÍµãĞÂÏÊÈËÈâ£¡ÄÇÊ±ºò±¾¹ÃÄïÒ»¸ßĞË£¬Ëµ²»¶¨¾ÍÊÕÏÂÄãÁË¡£");
    return 1;
  }
  command("grin");
  command("say ±¾¹ÃÄï×î°®³ÔÈËÈâ°ü×ÓÁË¡£"+myname+"±ğÍüÁË¶à¸ø³ø·¿ÅªµãÔ­ÁÏ£¡");
  command("recruit "+myid);
  return 1;
}
int prevent_learn(object me, string skill)
{
  string myname=RANK_D->query_rude(me);

  if(skill == "kugu-blade")
  { 
    message_vision(CYN"±ÌÊó¾«Å­µÀ£ºÃ»ÃÅ¶ù£¡²»½Ì£¡\n", me);
    return 1;
  }
  return 0;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob))
  {
    ob->set("class", "yaomo");
  }
}
/************************************************************/

int accept_object(object me, object ob)
{
    if (ob->query("name_recognized") != "°×¹ÇÁî")
	return notify_fail(CYN"±ÌÊóÅ­µÀ£º»ìÕÊ£¬ÎÒÓÖ²»ÊÇÊÕÆÆÀÃµÄ£¡\n"NOR);
    remove_call_out("bishu_leave");
    call_out("bishu_leave", 1, me);
    return 1;
}
void bishu_leave(object me)
{
    command("say Õâ¡¢Õâ¡¢Õâ£¬Õâ¿ÉÔõÃ´°ìÊÇºÃ£¿");
    command("sigh");
    command("say ¼ÈÈ»·òÈËÓĞÁîÔÚ´Ë£¬ÎÒ»¹ÊÇ¸Ï½ô»ØÈ¥Ò»ÌË°É£¡");
    message_vision("±ÌÊó¾«×¥ÁËÒ»°ÑÍÁ£¬Ïò¿ÕÖĞÒ»Å×£¬ºÈÉù£º×ß£¡½èÍÁ¶İÈ¥ÁË¡£\n", me);
    destruct(this_object());
    return;
}
ÿ
