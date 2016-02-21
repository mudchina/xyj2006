// zaoshen.c

inherit F_VENDOR_SALE;

void create()
{
        set_name("灶王爷", ({"zao wangye","wangye"}));
        set("title", "南城客栈");
        set("gender", "男性" );
        set("age", 16);
        set("long", "一个被供养得胖胖的灶王爷，正冲着你笑．\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
	set("vendor_goods", ([
//      		"renshen guo": "/d/obj/drug/renshen-guo",
		"parry book": "/d/obj/book/parrybook2.c",
		"force book": "/d/obj/book/forcebook2.c",
		]) );

        setup();

}
void init()
{
//add_action("do_yao", "yao");
        add_action("do_vendor_list", "list");
add_action("do_yao","yao");
}

int do_yao(string arg)
{
        object m,mm,me;
        message_vision("$N嬉皮笑脸地向灶王爷问道:我是新来的，有没有见面礼呀?\n", this_player());
	me=this_player();
        if ( me->query("wizgift/newbiegift") )
         return notify_fail("灶王爷一瞪眼：想蒙我？\n"); 
//	if ( me->query("combat_exp") < 5000 )
//	 return notify_fail("灶王爷说道: 小家伙练点功夫再来罢!\n");
//
        m=new("/d/obj/drug/giftbox");
//        mm=new("/obj/money/thousand-cash");
        m->move(this_player());
//        mm->move(this_player());
	me->set("wizgift/newbiegift",1);
	log_file("static/NEWBIEGIFT","["+ctime(time())+"] "+sprintf("%s(%s)从灶王爷处得到了%s(%s)\n",
         this_player()->query("name"),this_player()->query("id"),
         m->query("name"),m->query("id")));
	message_vision("灶王爷给$N一个礼品盒.\n", this_player());
//        message_vision("灶王爷给$N一张一千两的银票\n",this_player()); 
        message_vision("灶王爷对$N笑道：好好练。\n", this_player());
return 1;
}

int do_bid(string arg)
{
	if (!wizardp(this_player()))
	  return notify_fail("你不能在这里当老板。:-) \n");
 	return ::do_bid(arg);
}

