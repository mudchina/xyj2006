
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("生日蛋糕" , ({"cake"}));
        set_weight(1);
        set("unit", "个");
        set("long", "一个好大的奶油蛋糕,专为庆祝生日而做。\n");
        set("value",100000);
        set("no_get",1);
        set("no_drop","这么好吃的糕，可不能随便扔！ \n");
        setup();
}

void init()
{
       
        add_action("do_eat","eat");
        if (!query("owner")) add_action("do_celebrate","celebrate");
        else {
          add_action("do_cut","cut");
          add_action("do_blow","blow");
          add_action("do_wish","wish");
        }              
          
}

int do_eat(string arg)
{
        object me = this_player();
 
        if (!id(arg))
           return notify_fail("你要吃什么？\n");
        write(HIW
"想一个人吃这么大一个蛋糕？
别做梦了。还是切(cut)开来分着吃吧。\n"NOR,me);
        return 1;
}

int do_cut(string arg)
{
        object *alluser,obj,cakepiece;
        int s;
        object me = this_player();
        object room=environment(this_player());
        
        if (query("owner")!=getuid(me))
            return notify_fail("又不是你过生日，不要瞎积极！\n");
        if (!arg || arg!="cake")
           return notify_fail("你要切什么？\n");
        
        if (!query("blow")) return notify_fail("先吹(blow candle)蜡烛。\n");
        alluser=users();        
        s=sizeof(alluser);
        message_vision(HIW"$N把大蛋糕切成了"+chinese_number(s)+ 
              "小块。\n$N给大家一人分了一小块蛋糕。\n"NOR,me);

        
        for (int i=0;i<s;i++) {
            obj=alluser[i];
            cakepiece=new(__DIR__"cakepiece");
            cakepiece->move(obj);
            if (obj!=me)
              message("vision",me->query("name")+"分你一块生日蛋糕。\n",obj);
        }

        destruct(this_object());
        return 1;
}

int do_celebrate(string arg) {

    object me,obj;
    string msg;
    int space;
    me=this_player();
    if (query("owner")) return 0;
    if (!arg) return notify_fail("你要给谁庆祝生日？\n");
    if(!objectp(obj = present(arg, environment(this_player()))))
         return notify_fail("这里没有这个人。\n");
    if(!userp(obj))
         return notify_fail("你烧的不轻！\n");
    if (obj==me) 
         write("你给自己准备了一个生日蛋糕。\n");
    else message_vision("$N对$n说：“生日快乐！”说完递上一个大蛋糕。\n",me,obj);

    this_object()->move(obj);
    set("owner",getuid(obj));       

    msg= HIR"                () () () () ()\n"+
         HIW"            @@@@"+HIY"|| || || || ||"+HIW"@@@@\n"+
         "           @    "+HIY"|| || || || ||"+HIW"    @\n"+
         "          @@                      @@\n"+
         "          @@";
    space=(14-strlen(obj->query("name")))/2;
    for (int i=0;i<space;i++) msg+=HIG" ";
    msg+=obj->query("name")+"生日快乐";
    for (int i=0;i<space;i++) msg+=" ";
    msg+=HIW"@@\n"+
         "          @@    "+HIM"@>-  @>-  @>-     "+HIW"@@\n"+
         "           @    "+HIM"@>-  @>-  @>-     "+HIW"@\n"+
         "            @@@@@@@@@@@@@@@@@@@@@@\n"NOR;
    set("long",msg);   
    this_object()->move(obj);
   
    remove_action("do_celebrate","celebrate"); 
    return 1;
}

int do_wish(string arg) {

    object me=this_player();

    if (!arg) return notify_fail("你要许什麽愿？\n");
    if (query("owner")!=getuid(me)) notify_fail("又不是你过生日，许什麽愿！\n");
    
    write("祝愿"+arg+"\n");
    message_vision("$N闭上双眼，嘴里嘟嘟囔囔不知道说了些什麽。\n",me); 
  
    set("wish",1);
    remove_action("do_wish","wish");
    return 1;
}

int do_blow(string arg)  {
    object me=this_player();

    if (!arg || arg!="candle") return notify_fail("吹什麽？\n");
    if (query("owner")!=getuid(me)) 
       notify_fail("又不是你过生日，不要瞎积极！\n");
    if (!query("wish")) return notify_fail("先许(wish)个愿。\n");

    message_vision("$N深深地吸了一口气，鼓起腮帮，一口气吹熄了蜡烛。\n",me); 
    remove_action("do_blow","blow");
    set("blow",1);
    return 1;
}

