// horsetrainer2.c writted by jie 2001-2-5
// 坐骑训练之二，增加坐骑的属性除了int,kar都会改进
// 花费gold
// u/jie/horsetrainer2
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("猢马官", ({ "bimawen hu", "hu"}) );
        set("gender", "女性" );
        set("title",HIY"候补弼马温"NOR);
        set("age", 44);
        set("long","一个颇有灵性的猴妖，经她相(train)过的坐骑，属性都有变化。\n由于齐天大圣也任过此贱职，所以弼马温一职一直空悬，禄俸倒十分丰厚。\n");
        set("combat_exp", 50000);
        set("daoxing", 60000);
        set("attitude", "friendly");
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );
        setup();
        carry_object("/d/qujing/tianzhu/obj/guanpao")->wear();

}

void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_train", "train");

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "猢马官说道：这位" + RANK_D->query_respect(ob)
                                + "，老妇天界人称女伯乐，善于相马！\n");
                        break;
                case 1:
                        say( "猢马官笑道：虽是候补弼马温，但是俸禄不少，全托孙大圣的福！\n");

                        break;
        }
}

int do_train(string arg)
{
        object ob;
        object pet_ob;
        string pet_id;
        object gold;
        int cost;
        string which;
        ob = this_player();
        if(ob->is_busy())
        return notify_fail("你正忙着呢。\n");
        if (!ob->query("pet/pet_id"))
        return notify_fail("猢马官道：＂你并没有坐骑，来凑什么热闹？＂\n");
        pet_id=ob->query("pet/pet_id");
        if( !objectp(pet_ob=present(pet_id, ob)) && 
                !objectp(pet_ob=present(pet_id, environment(ob))))
        return notify_fail("猢马官道：＂你的坐骑没和你一起来吗？＂\n");
        if(pet_ob->query("owner") != ob->query("id")) 
        return notify_fail("猢马官道：＂那好象不是你的吧？＂\n");
        switch (random(6)){
        case 0: which = "str"; break;
        case 1: which = "cor"; break;
        case 2: which = "per"; break;
        case 3: which = "spi"; break;
        case 4: which = "cps"; break;
        case 5: which = "con"; break;
                }       
//好，我们现在花钱来增加坐骑的六大属性之一
        cost = (int) pet_ob->query(which) ;
        cost *= cost;
        gold = present("gold_money", ob);
        if(!gold) return notify_fail("你身上没有金子。\n");
        if((int) gold->query_amount() < cost)
        return notify_fail("你身上没有"+chinese_number(cost)+"两金子。\n");
        pet_ob->add(which,1);
        pet_ob->save();
        gold->add_amount(-cost);
        command("say 不错不错！！下次老妇再帮你相！\n");
        return 1;
}

