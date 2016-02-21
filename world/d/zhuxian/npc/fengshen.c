#include <ansi.h>
int wind();

inherit NPC;
void create()
{
  set_name("·çÉñ", ({"feng shen", "fengshen", "shen"}));
  set("gender", "ÄÐÐÔ");
  set("attitude", "friendly");
  set("combat_exp", 3000000);
  set("daoxing", 3000000);

  set("age", 100);
  set("per", 100);
  set("str", 30);
  set("int", 30);
  set("cor", 30);
  set("cps", 30);
  set("con", 30);
  set("max_kee", 6000);
  set("max_sen", 4000);
  set("force", 5000);
  set("max_force", 5000);
  set("max_mana", 3000);
  set("mana",6000);  
  set("mana_factor",200);  
  set("force_factor",200);  
  set_skill("spells", 250);
  set_skill("force", 250);
  set_skill("unarmed", 250);
  set_skill("puti-zhi", 250);
  set_skill("parry", 250);
  set_skill("wuxiangforce", 250);
  set_skill("dao", 250);
  set_skill("dodge", 250);
  set_skill("jindouyun", 250);
  map_skill("dodge", "jindouyun");
  map_skill("unarmed", "puti-zhi");
  map_skill("spells", "dao");
  map_skill("force", "wuxiangforce");

         set("chat_chance_combat", 50);
         set("chat_msg_combat", ({
        (: wind :)
       }));
        set_temp("apply/armor", 300);

  setup();
}
int wind()
{
remove_call_out("hurting");
message_vision( HIC "\n\n$NÊÖÒ»Ñï£¬Ò»Õó¿ñ·ç´µÆð£¡£¡\n\n" NOR,
this_object());
call_out("hurting",random(10)+2);

        return 1;
}

int hurting()
{
        int i;
        int dam;
        object *inv;
        message_vision( HIC "\n\n¿ñ·ç´µ¹ý£¬Á¬´óµØ¶¼¿ì±»´µÁÑ£¡£¡£¡\n\n",this_object());
        inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
        if( living(inv[i]))
        if( inv[i] != this_object())
        {
        dam = random(500)+200 ;
        inv[i]->receive_damage("kee",dam);
        inv[i]->receive_wound("kee",dam/2);
        COMBAT_D->report_status(inv[i]);
        }
        return 1;
}

void die()
{
    object rope;
    string rp="/d/zhuxian/obj/xianxian.c";

	rope = new(rp);
    if( environment() ) {
    message("vision", "Ò»Õó¿ñ·ç¹Î¹ý£¬·çÉñÏûÊ§µÄÎÞÓ°ÎÞ×Ù£¬ÄãÍ»È»·¢ÏÖµØÉÏ¶àÁËÒ»Ñù¶«Î÷¡£\n", environment());
    }
    rope->move(environment(this_object()));
    destruct(this_object());
}
ÿ
