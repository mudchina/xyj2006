#include <ansi.h>
int fire();

inherit NPC;
void create()
{
  set_name("»ðÉñ", ({"huo shen", "huoshen", "shen"}));
  set("gender", "ÄÐÐÔ");
    set("attitude", "peaceful");
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
        (: fire :)
       }));
        set_temp("apply/armor", 300);

  setup();
}
int fire()
{
remove_call_out("hurting");
message_vision( HIR "\n\n$N¿ÚÖÐÄîÄîÓÐ´Ê£¬Ò»Õó»ð¹âÏ®À´£¡£¡\n\n" NOR,
this_object());
call_out("hurting",random(10)+2);

        return 1;
}

int hurting()
{
        int i;
        int dam;
        object *inv;
        message_vision( HIR "\n\n»ð£¬»ð£¬»ð£¬Õû¸öÊÀ½ç¾ÍÖ»Ê£ÏÂ»ð£¡£¡£¡\n\n" NOR, this_object());
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
    string rp="/d/zhuxian/obj/luxian.c";

	rope = new(rp);
    if( environment() ) {
    message("vision", "»ðÖÕÓÚÏ¨ÃðÁË£¬ÊÀ½çÖØÐÂÇå¾»ÏÂÀ´£¬»ðÉñËÆºõµôÏÂÁËÒ»Ñù¶«Î÷¡£\n", environment());
    }
    rope->move(environment(this_object()));
    destruct(this_object());
}
ÿ
