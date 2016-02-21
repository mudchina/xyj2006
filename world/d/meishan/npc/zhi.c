
inherit NPC;
void consider();
void create()
{

  set_name("Ö±½¡", ({ "zhi jian", "zhi", "jiangjun" }) );
  set("gender", "ÄĞĞÔ" );
  set("long", "Ö±½¡ÊÇÃ·É½ÆßĞÖµÜÖĞµÄÀÏÈı¡£\n");
  set("title", "Ã·É½½«¾ü");
  set("age", 45);
  set("attitude", "peaceful");
  set("str", 30);
  set("int", 25);
  set("combat_exp",790000);
  set("force",1500);
  set("max_force",1000);
  set("force_factor", 70);
  set("max_kee", 1000);
  set("max_sen", 1000);
  set("max_mana", 800);
  set("mana", 1500);
  set("mana_factor", 40);

        set("eff_dx", 300000);
        set("nkgain", 400);

  set_skill("unarmed",145);
  set_skill("dodge",145);
  set_skill("parry", 145);
  set_skill("staff",145);
  set_skill("force",140);
        set_skill("spells", 100);
        set_skill("dao", 50);
        set_skill("moyun-shou", 145);
        set_skill("wuxiangforce", 140);
        set_skill("lunhui-zhang", 145);
        set_skill("moshenbu", 145);
        map_skill("spells", "dao");
        map_skill("unarmed", "moyun-shou");
        map_skill("force", "wuxiangforce");
        map_skill("staff", "lunhui-zhang");
        map_skill("parry", "lunhui-zhang");
        map_skill("dodge", "moshenbu");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: consider :)
        }) );

  setup();
  carry_object("/d/obj/armor/yinjia")->wear();
  carry_object("/d/obj/weapon/staff/budd_staff")->wield();
}

int accept_fight(object me)
{       me= this_object();
        if( (int)me->query("kee")*100/(int)me->query("max_kee") >= 50 ) {
                if( (int)me->query("kee")*100/(int)me->query("max_kee") >= 80 ) {

                        command("ok");
                        command("unwield staff");
                        command("enable unarmed none");
                        return 1;
                        }
                command("nod");
                command("wield staff");
                command("enable unarmed moyun-shou");
                return 1;
        }
        command("say ÎáÓĞ¹«ÎñÔÚÉí£¬Ë¡²»·îÅã£¡\n");
        return 0;
}

void consider()
{

        int i, flag = 0;
        object *enemy;

        enemy = query_enemy() - ({ 0 });
        for(i=0; i<sizeof(enemy); i++) {
                if( !living(enemy[i]) ) continue;
                        flag++;
                if(     !query_temp("weapon") ) {
                command("say ¸óÏÂ¹¦·ò³¬Èº£¬ÔÚÏÂ±ãÒ²²»¿ÍÆøÁË£¡\n");
                        command("wield staff");
                        command("enable unarmed moyun-shou");
                        break;
                }
        }
}

ÿ