//sgzl

inherit NPC;

int have_fu;

string give_fu(object who);
int do_yes(string arg);

void create()
{
set_name("·çÆÅ",({"feng po","feng shen","po"}));
set("gender", "Å®ĞÔ");
set("age", 35);
set("long", "    \nÌì¹¬ÖĞ¸ºÔğÆğ·çµÄÌìÉñ£¬ÏëÒª¹Î·çÏÂÓêÊ±£¬Ã»ÓĞËı\nµÄ°ïÖúÊÇ²»ĞĞµÄ¡£\n");

set("attitude", "heroism");
set("class", "xian");

    set("combat_exp", 60000);
  set("daoxing", 100000);


set("kee", 600);
set("max_kee", 600);
set("sen", 650);
set("max_sen", 650);
set("force", 800);
set("max_force", 800);
set("mana", 1000);
set("max_mana", 1000);
set("force_factor", 20);
set("mana_factor", 30);
set("per", 18);


set_skill("dodge", 80);
set_skill("moondance", 40);
set_skill("unarmed", 100);
set_skill("baihua-zhang", 70);
set_skill("parry", 120);


map_skill("dodge", "moondance");
map_skill("unarmed", "baihua-zhang");
set("inquiry", ([
  "ÏÂÓê"   : "ÏëÇóÓê£¬¹âÎÒÒ»¸öÈË¿É²»¹»¡£",
  "rain"   : "ÏëÇóÓê£¬¹âÎÒÒ»¸öÈË¿É²»¹»¡£",
  "Æğ·ç"   : (: give_fu :),
  "¹Î·ç"   : (: give_fu :),
  "wind"   : (: give_fu :),
  "name"   : "ÎÒ¾ÍÊÇ¸ºÔğÆğ·çµÄ·çÉñ¡£",
  "here"   : "Õâ¾ÍÊÇÌì¹¬Ñ½¡£",
]));


setup();

carry_object("/obj/loginload/skirt.c")->wear();
carry_object("/obj/loginload/shoes.c")->wear();
add_money("silver", 10);

}


void init()
{
  have_fu=1;
  add_action("do_yao", "yao");
}

string give_fu(object who)
{
  who=this_player();
  if ( (who->query("combat_exp")<10000) || (who->query("mana") < 500 ) )
    {
    return "¿´À´Äã»¹²»¶®ÔõÃ´ºô·ç»½Óê£¬ÔÙºÃºÃĞŞÁ¶ĞŞÁ¶°É¡£\n";
    }
  else
    {
    who->set_temp("need_fengfu", 1);
    return "ÎÒÓĞÕÅÁé·û£¬ÓÃËü¿ÉÒÔÆğ·ç£¬ÄãÏëÒªÂğ(yao)£¿\n";
    }
}

int do_yao(string arg)
{
  object me=this_object();
  object who=this_player();
  object fu;
   if(who->query_temp("need_fengfu")) 
   {
      message_vision("$N´ğµÀ£ºÏëÒª£¡\n", who);

      if (have_fu==1)    
         {
         message_vision("·çÆÅËµµÀ£ººÃ°É£¡ÄãÀ´ÊÔÊÔ¿´ÕâÍæÒâÁé²»Áé¡£\n", who);
         fu = new ("/d/dntg/sky/obj/fenglingfu");
         fu ->move(who);
         message_vision ("$N½»¸ø$nÒ»ÕÅ·çÁé·û¡£\n",me,who);
         have_fu=0;
         }
      else 
         {
         message_vision("·çÆÅËµµÀ£º°¥Ñ½£¬ÊµÔÚ²»ºÃÒâË¼£¬ÎÒ¸Õ°ÑËü¸ø±ğÈËÁË£¬ÄãµÈ»á¶ùÔÚÀ´Òª°É¡£\n", who);
         }
      return 1;

  }
}
ÿÿ
