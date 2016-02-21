
inherit NPC;
void consider();
void create()
{

  set_name("π˘…Í", ({ "guo shen", "guo", "jiangjun" }) );
  set("gender", "ƒ––‘" );
  set("long", "π˘…Í «√∑…Ω∆ﬂ–÷µ‹÷–µƒ¿œ∂˛°£\n");
  set("title", "√∑…ΩΩ´æ¸");
  set("age", 45);
  set("attitude", "peaceful");
  set("str", 30);
  set("int", 25);
  set("combat_exp",800000);
  set("force",1000);
  set("max_force",1500);
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
  set_skill("sword",145);
  set_skill("force",140);
        set_skill("spells", 100);
        set_skill("dao", 50);
        set_skill("moyun-shou", 145);
        set_skill("wuxiangforce", 140);
        set_skill("sanqing-jian", 145);
        set_skill("moshenbu", 145);
        map_skill("spells", "dao");
        map_skill("unarmed", "moyun-shou");
        map_skill("force", "wuxiangforce");
        map_skill("sword", "sanqing-jian");
        map_skill("parry", "sanqing-jian");
        map_skill("dodge", "moshenbu");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: consider :)
        }) );

  setup();
  carry_object("/d/obj/armor/yinjia")->wear();
  carry_object("/d/obj/weapon/sword/qingfeng")->wield();
}

int accept_fight(object me)
{       me= this_object();
        if( (int)me->query("kee")*100/(int)me->query("max_kee") >= 50 ) {
                if( (int)me->query("kee")*100/(int)me->query("max_kee") >= 90 ) {

                        command("ok");
                        command("unwield sword");
                        return 1;
                        }
                command("nod");
                command("wield sword");
                return 1;
        }
        command("say Œ·”–π´ŒÒ‘⁄…Ì£¨À°≤ª∑Ó≈„£°\n");
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
                command("say ∏Ûœ¬π¶∑Ú≥¨»∫£¨‘⁄œ¬±„“≤≤ªøÕ∆¯¡À£°\n");
                        command("wield sword");
                        break;
                }
        }
}

ˇ