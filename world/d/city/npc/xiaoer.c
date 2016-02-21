
inherit F_VENDOR_SALE;
int random_go(object me, string* dirs);

// #include <norumor.c>
void create()
{
       reload("xiaoer");
       set_name("店小二", ({"xiao er","xiaoer","xiao","waiter","er"}));
       set("shop_id",({"waiter","xiaoer","xiao","er"}));
       set("shop_title","店小二");
       set("gender", "男性");
        set("combat_exp", 1000);
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
       set("max_price",20);
        set("vendor_goods", ([
                "jiudai": "/d/moon/obj/jiudai",
                "gourou": "/d/ourhome/obj/gourou",
              "jinpai" : "/d/obj/misc/tiaozhanpai",
"tu": "/d/city/obj/tu",
               "xmap": "/d/obj/misc/xueshan-map",
               "pmap": "/d/penglai/npc/obj/ditu",
               "pillow": "/d/obj/misc/pillow",
                "jitui": "/d/ourhome/obj/jitui",
               "ball": "/d/obj/misc/crystalball",
                "huasheng": "/d/ourhome/obj/huasheng",
                "zhinan": "/d/obj/misc/xiaqi-zhinan",
    "panshi dan": "/u/take/panshidan",
             "zhengsu":"/d/qujing/chechi/obj/zhengsu",
                "huicheng":"/d/city/obj/huicheng",
        ]) );

        if( clonep() ) CHANNEL_D->register_relay_channel("rumor");
       setup();

       carry_object("/d/obj/cloth/linen")->wear();
carry_object("/d/wiz/npc/caishen")->wear();
       add_money("silver", 1);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {  // 1/3 chance to greet.
                case 0:
                        say( name()+"笑咪咪地说道：这位" +RANK_D->query_respect(ob)
                                + "，进来歇歇脚，喝两盅吧。\n");
                        break;
        }
}

void clear_room()
{
        string *place1 =
        ({"/d/city/zhuque-s1","/d/city/center","/d/city/xuanwu-n1",
        "/d/city/baihu-w1","/d/city/qinglong-e1"});

        string room;
        int race, obj,i;
        object *inv;
        race = 0;
        obj = 0;
        if(environment(this_object())){
        inv = all_inventory(environment(this_object()));
      
        say(name()+"抱歉地说道：“小店清扫，各位客官原谅则个。”\n");
      

        if ( sizeof(inv) <= 0 ) return ;

        for (i = 0;i <sizeof(inv);i++)
        {
                if(inv[i]->query("race")=="野兽")
                {
                        room = place1[random(5)];
                        say(inv[i]->query("name")+"被"+name()+"用扫帚赶了出去。\n");
                        inv[i]->set_temp("no_return",0);
                        inv[i]->set_temp("rider",0);
                        inv[i]->move(room);
                        tell_room(environment(inv[i]), inv[i]->query("name")+"被"+name()+"从客栈赶了出来。\n");
                        race++;
                }
                else if(!inv[i]->is_character()&&!inv[i]->query("board_id")) 
                {obj++; destruct(inv[i]);}
                if(inv[i]->query_temp("ridee"))
                {

                        inv[i]->set_temp("ridee",0);
                        inv[i]->add_temp("apply/dodge",-inv[i]->query_temp("ride/dodge"));
                        inv[i]->set_temp("ride/dodge",0);

                 }
        }
      if(race+obj==0) say(name()+"不怀好意的扫了半天，发现没什么可以打扫的，怏怏的坐回了柜台。\n");
      CHANNEL_D->do_channel(this_object(),"sys","赶走坐骑"+chinese_number(race)+"只，清理垃圾"+chinese_number(obj)+"件。\n");
     }
      remove_call_out("clear_room");
      call_out("clear_room",300);
}
int accept_object(object who, object ob)
{
   if (ob->query("money_id") && ob->value() >= 300) 
   {
     tell_object(who, "小二一哈腰，说道：多谢您老，客官请上楼歇息。\n");
     who->set_temp("rent_paid",1);
     return 1;
   }
   return 0;
}
