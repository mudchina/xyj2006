#include <ansi.h>

inherit NPC;

string test_player();

mapping *poisons = ({
        ([      "name": "double_ice_poison",
                "base_amount": 100
        ]),
        ([      "name": "ice_poison",
                "base_amount": 50
        ]),
        ([      "name": "jjf_poison",
                "base_amount": 10
        ]), 
        ([      "name": "xiangsi",
                "base_amount": 100
        ]),
       ([      "name": "snake_poison",
                "base_amount": 10
        ]),
    ([  "name": "bp_poison",
        "base_amount": 10
    ]),
        ([      "name": "moon_poison",
                "base_amount": 100
        ]),
});

void create()
{
        set_name("雾渊道长", ({"wuyuan daozhang", "wuyuan", "daozhang","taoist"}));
        set("age", 62);
        set("gender", "男性");
        set("long",
"清虚观的主持，看起来仙风道骨．\n");
        set("attitude", "peaceful");
        set("class", "taoist");
        set("combat_exp", 180000);
  set("daoxing", 800000);

        set("shen_type", 1);

        set_skill("unarmed", 90);
        set_skill("dodge", 90);
        set_skill("parry", 90);
        set_skill("whip", 90);
        set_skill("force", 90);
        set_skill("spells", 80);
        set_skill("dao", 80);
        map_skill("spells", "dao");
        set("force", 400);
        set("max_force", 400);
        set("force_factor", 10);
        set("mana", 1000);
        set("max_mana", 600);
        set("mana_factor", 30);

        set("max_kee", 800);
        set("max_sen", 700);

        set("eff_dx", 80000);
        set("nkgain", 300);

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: cast_spell, "light" :),
                (: cast_spell, "thunder" :)
        }) );

        set("inquiry", ([
                "name": "贫道雾渊，本观主持就是贫道。",
                "here": "贫道粗通医术，要治病(cure)也许贫道可以试试看。",
                "cure": (: test_player :),
                "治病": (: test_player :),
        ]));

        set("chat_chance", 20);
        set("chat_msg", ({
"雾渊真人叹到：难难难，道最玄，莫把金丹作等闲．\n",
}) );
        setup();
        carry_object("/d/obj/weapon/whip/fuchen")->wield();
        carry_object("/d/lingtai/obj/cloth")->wear();
}

string test_player()
{
        object me=this_player(), npc=this_object();
        mapping poison;
        int i;
        int amount, duration, total;

        total=0;
        message_vision(CYN "$n伸出右手，搭在$N手腕上。\n"NOR, me, npc);
        message_vision(CYN "过了片刻，$n缓缓说道：\n" NOR, me, npc);
        for(i=0;i<sizeof(poisons);i++) {
                poison=poisons[i];
                duration=me->query_condition(poison["name"]);
                if(duration>0) {
                        amount=poison["base_amount"]*duration;
                        message_vision(CYN ""+poison["name"]+"："+chinese_number(amount)+"两白银,\n" NOR, me, npc);
                        total+=amount;
                }
        }
        if(me->query("eff_kee")<me->query("max_kee")) {
                duration=me->query("max_kee")-me->query("eff_kee");
                amount=duration;
                message_vision(CYN "气血："+chinese_number(amount)+"两白银,\n" NOR, me, npc);
                total+=amount;
        }
        if(me->query("eff_sen")<me->query("max_sen")) {
                duration=me->query("max_sen")-me->query("eff_sen");
                amount=duration;
                message_vision(CYN "精神："+chinese_number(amount)+"两白银,\n" NOR, me, npc);
                total+=amount;
        }
        me->set_temp("cure_payment", total);
        if(total>0) {
                message_vision(CYN "一共需要"+chinese_number(total)+"两白银。\n" NOR, me, npc);
                return "交医药费吧！";
        }
        message_vision(CYN ""+RANK_D->query_respect(me)+"又没病，怎么治？\n" NOR, me, npc);
        return "一边玩去！";
}

int accept_object(object who, object ob)
{
        object me = this_object();
        mapping poison;
        int total = who->query_temp("cure_payment");
        int value=ob->value();
        int duration,i;

        if(total==0) {
                command("say "+RANK_D->query_respect(who)+"这是干什么？");
                return 0;
        }
        if(total*100>value) {
                command("say 医药费一共需要"+chinese_number(total)+"两白银。");
                return 0;
        }
        message_vision(CYN "$N掏出几支金针，刺入$n人中，印堂，左手劳宫，右膝足三里等穴道。\n" NOR, me, who);
        message_vision(CYN "片刻之后，$N将金针一一拔下，\n$n只觉得嗓子眼发咸，张嘴吐出一口五彩斑斓的鲜血。\n" NOR, me, who);
        command("pat "+who->query("id"));
        command("say 差不多了。");
        for(i=0;i<sizeof(poisons);i++) {
                poison=poisons[i];
                duration=who->query_condition(poison["name"]);
                if(duration>0) {
                        who->apply_condition(poison["name"], 0);
                }
        }
        who->set("eff_kee", who->query("max_kee"));
        who->set("eff_sen", who->query("max_sen"));
        return 1;
}

