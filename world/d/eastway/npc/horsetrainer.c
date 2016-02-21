// horsetrainer.c writted by jie 2001-2-5
// 坐骑训练之一，增加坐骑的气血、精神
// 花费gold
// u/jie/horsetrainer
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("狲马官", ({ "bimawen sun" ,"sun"}) );
        set("gender", "男性" );
        set("title",HIY"候补弼马温"NOR);
        set("age", 32);
        set("long","一个颇有灵性的猴妖，对改善坐骑(train)的体质别有妙技。\n由于齐天大圣也任过此贱职，所以弼马温一职一直空悬，禄俸倒十分丰厚。\n");
        set("combat_exp", 50000);
        set("daoxing", 60000);
        set("attitude", "friendly");
        set("chat_chance", 15);
        
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
                        say( "狲马官说道：这位" + RANK_D->query_respect(ob)
                                + "，来找我养马么？\n");
                        break;
                case 1:
                        say( "狲马官笑道：虽是候补弼马温，但是俸禄不少，全托孙大圣的福！\n");
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
        return notify_fail("狲马官道：＂你并没有坐骑，来凑什么热闹？＂\n");
        pet_id=ob->query("pet/pet_id");
        if( !objectp(pet_ob=present(pet_id, ob)) && 
                !objectp(pet_ob=present(pet_id, environment(ob))))
        return notify_fail("狲马官道：＂你的坐骑没和你一起来吗？＂\n");
        if(pet_ob->query("owner") != ob->query("id")) 
        return notify_fail("狲马官道：＂那好象不是你的吧？＂\n");
        switch (random(3)){
        case 0: which = "max_gin"; break;
        case 1: which = "max_kee"; break;
        case 2: which = "max_sen"; break;
                        }       
//好，我们现在花钱来增加坐骑的精、气、神之一
        cost = (int) pet_ob->query(which) / 10;
        cost *= cost;
        gold = present("gold_money", ob);
        if(!gold) return notify_fail("你身上没有金子。\n");
        if((int) gold->query_amount() < cost)
        return notify_fail("你身上没有"+chinese_number(cost)+"两金子。\n");
        pet_ob->add(which,10);
        pet_ob->save();
        gold->add_amount(-cost);
        command("say 贵乎自然啊，我溜达它一趟不就好多了！\n");
        return 1;
}

