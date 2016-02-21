// guanjia.c
// 9-2-97 pickle

inherit NPC;
inherit F_MASTER;
string expell_me(object me);
void create()
{
  set_name("ÌïÊó¾«", ({"tian shu", "tian", "shu", "tianshu", "monster"}));
  set("gender", "Å®ÐÔ");
  set("age", 23);
  set("long",
"Ëý¾ÍÊÇÎÞµ×¶´µÄ´ó¹Ü¼Ò¡£Ïëµ±ÄêËýºÍÓñÊóÒ»ÆëÐÞÏÉ³ÉÁËÈËÐÎ£¬\n"
"µ«Òò×ÊÖÊÌ«²î£¬³ÉÕý¹ûÖÕ¾¿ÊÇÎÞÍû¡£ÕÕ¹Ë×Åµ±ÄêµÄ½»Çé£¬ÓñÊó\n"
"°²ÅÅËý×öÁËÕâ¶´µÄ¹Ü¼Ò¡£\n");
  set("title", "´ó¹Ü¼Ò");
  set("cor", 25);
  set("combat_exp", 200000);
  set("daoxing", 400000);

  set("attitude", "heroic");
  create_family("ÏÝ¿ÕÉ½ÎÞµ×¶´", 2, "µÜ×Ó");
  set_skill("literate", 10);
  set_skill("unarmed", 55);
  set_skill("parry", 55);
  set_skill("spells", 55);  
  set_skill("sword", 55);  
  set_skill("qixiu-jian", 55);
  set_skill("yinfeng-zhua", 55);
  set_skill("lingfu-steps", 55);
  set_skill("dodge", 55);
  set_skill("force", 55);
  set_skill("yaofa", 55);
  set_skill("huntian-qigong", 55);
  map_skill("force", "huntian-qigong");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("spells", "yaofa");
  map_skill("sword", "qixiu-jian");
  map_skill("parry", "qixiu-jian");
  map_skill("dodge", "lingfu-steps");
  
  set("str", 30);
  set("per", 30);
  set("max_kee", 300);
  set("max_sen", 300);
  set("force", 350);
  set("max_force", 350);
  set("force_factor", 20);
  set("mana", 550);
  set("max_mana", 500);
  set("mana_factor", 25);
  set("inquiry", ([
                   "ÅÑÃÅ": (: expell_me :),
                   "leave": (: expell_me :),
		   "name": "±¾¹ÃÄï¾ÍÊÇÕâÎÞµ×¶´µÄ´ó×Ü¹Ü£¡",
		   "here": "ÄãÏ¹ÁËÑÛÀ²£¿ÕâÀï¾ÍÊÇ¶¦¶¦´óÃûµÄÏÝ¿ÕÉ½ÎÞµ×¶´£¡",
		   "rumors": "²»ÖªµÀ£¡ÕÒ±ðÈËÎÊÈ¥¡£",
		   "ÈËÈâ°ü×Ó": "ÄãÏ¹ÁËÑÛÀ²£¿±¾¹ÃÄïÓÖ²»ÊÇ³ø×Ó£¡",
                 ]) );  
  setup();
  carry_object("/d/obj/weapon/blade/blade.c")->wield();
  carry_object("/d/obj/cloth/yuanxiang")->wear();
  carry_object("/d/obj/cloth/nichang")->wear();
}
int attempt_apprentice(object me)
{
  string myname=RANK_D->query_rude(me);
  string myid=me->query("id");
  command("look "+myid);
  command("consider");
  if (me->query("combat_exp")+me->query("daoxing")>400000)
  {
    command("say "+myname+"À´¸ÉÊ²Ã´£¿ÏëÀ´ÇÀÀÏÄïµÄÎ»×Ó£¿\n");
    return 1;
  }
  if (me->query("wudidong/sell_reward")<1000)
  {
    command("say "+myname+"ÒªÏëÀ´ÎÞµ×¶´£¬ÏÈÌá¼¸¿ÅÈËÍ·À´Ð¢¾´ÎÒ£¡\n");
    return 1;
  }
  command("grin");
  command("say ÀÏÄï×î°®³ÔÈËÈâ°ü×ÓÁË¡£"+myname+"±ðÍüÁË¶à¸ø³ø·¿ÅªµãÔ­ÁÏ£¡");
  command("recruit "+myid);
  return 1;
}
int prevent_learn(object me, string skill)
{
  string myname=RANK_D->query_rude(me);

}
string expell_me(object me)
{
  me=this_player();

  if((string)me->query("family/family_name")=="ÏÝ¿ÕÉ½ÎÞµ×¶´")
  {
    me->set_temp("wudidong/betray", 1);
    return ("Ê²Ã´£¿ÏëÒªÀë¿ª£¿ÄÇÄã¾Í±ð¹ÖÀÏÄï³Í·££¡(jieshou)\n");
  }
  return ("ÄãÊÇÄÄÀïÀ´µÄ£¡¹ö£¡\n");
}
void init()
{
    add_action("do_accept", "jieshou");
}
int do_accept(string arg)
{
    object me=this_player();
    if (arg) return notify_fail("ÄãÒª¸ÉÊ²Ã´£¿\n");
    if (!me->query_temp("wudidong/betray")) return notify_fail("ÄãÒª½ÓÊÜÊ²Ã´£¿\n");
    message_vision("$NµÀ£º²»´í£¬ÎÒÒªÀë¿ªÎÞµ×¶´ÕâºÄ×ÓÎÑ£¡\n", me);
    me->add("betray/count", 1);
    me->add("betray/wudidong", 1);
    me->delete("family");
    me->delete("class");
    me->set("title", "ÆÕÍ¨°ÙÐÕ");
this_player()->set("combat_exp",this_player()->query("combat_exp")/5*4);
this_player()->set("daoxing",this_player()->query("daoxing")/5*4);
    if (me->query_skill("yaofa"))
    {
        me->delete_skill("yaofa");
	//me->set_skill("yaofa", me->query_skill("yaofa")/2);
	//if (me->query_skill("yaofa")>30) me->set_skill("yaofa", 30);
    }
    if (me->query_skill("huntian-qigong"))
    {
        me->delete_skill("huntian-qigong");
	//me->set_skill("huntian-qigong", me->query_skill("huntian-qigong")/2);
	//if (me->query_skill("huntian-qigong")>30) me->set_skill("huntian-qigong", 30);
    }
    me->save();
    return 1;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob))
  {
    ob->set("class", "yaomo");
  }
}
ÿ
