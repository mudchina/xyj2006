// horsetrainer2.c writted by jie 2001-2-5
// 坐骑训练之三，增加坐骑的武学，道行
// 花费gold
// u/jie/horsetrainer3
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("小马官", ({ "bimawen xiao", "xiao"}) );
        set("gender", "女性" );
        set("title",HIY"候补弼马温"NOR);
        set("age", 18);
        set("long","一个颇有灵性的小猴妖，她常和坐骑撕打(train)来增加坐骑的战斗力。\n由于齐天大圣也任过此贱职，所以弼马温一职一直空悬，禄俸倒十分丰厚。\n");
        set("combat_exp", 5000);
        set("daoxing", 1000);
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
                        say( "小马官说道：这位" + RANK_D->query_respect(ob)
                                + "，让它和我对打（train），你付金子？\n");
                        break;
                case 1:
                        say( "小马官笑道：这位" + RANK_D->query_respect(ob)
                                + "，放心！伤不到它的！\n");

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
        return notify_fail("小马官道：＂你并没有坐骑，来凑什么热闹？＂\n");
        pet_id=ob->query("pet/pet_id");
        if( !objectp(pet_ob=present(pet_id, ob)) && 
                !objectp(pet_ob=present(pet_id, environment(ob))))
        return notify_fail("小马官道：＂你的坐骑没和你一起来吗？＂\n");
        if(pet_ob->query("owner") != ob->query("id")) 
        return notify_fail("小马官道：＂那好象不是你的吧？＂\n");
        switch (random(2)){
        case 0: which = "combat_exp"; break;
        case 1: which = "daoxing"; break;
        }
//好，我们现在花钱来增加坐骑的wx, dh
        cost = to_int(sqrt(to_float(((int)pet_ob->query("combat_exp")+(int)pet_ob->query("combat_exp")+100))))/5;
        gold = present("gold_money", ob);
        if(!gold) return notify_fail("你身上没有金子。\n");
        if((int) gold->query_amount() < cost)
        return notify_fail("你身上没有"+chinese_number(cost)+"两金子。\n");
        pet_ob->add(which,cost*50);
        pet_ob->save();
        gold->add_amount(-cost);
        command("say 好了！下次再打！\n");
        return 1;
}

