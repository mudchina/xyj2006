//Cracked by Roath

inherit NPC;

void create()
{
       set_name("老者", ({"lao zhe","old man"}));
       set("long","一个满头白发的老者。\n");
       set("gender", "男性");
       set("age", 66);
       set("combat_exp", 1800);
       set("daoxing", 1800);
        set("chat_chance",60);
        set("chat_msg", ({
        "老者叹息道：“西天取经难啊，要取经，得到东天去吧。\n",
        "老者喃喃的说道：“前面有妖怪啊。”\n",
        }));
        setup();
        add_money("coin", 50);
        carry_object("/d/gao/obj/bang")->wield();

}

