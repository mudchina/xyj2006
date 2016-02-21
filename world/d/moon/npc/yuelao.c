//By waiwai@mszj 2000/07/12 优化

inherit NPC;
#include <ansi.h>

int do_register();
int do_zuomei(string);
int do_divorce(string);

void create()
{
   set_name(HIG "月下老人" NOR, ({ "yuexia laoren", "yuelao", "laoren" }));
   set("long",HIC 
"他就是专管天上地下姻缘的月下老人了。
他满脸红光，须眉皆白，正坐在那儿翻看一本书，
手上黏着一根红绳，口中正自言自语着些什么。\n"NOR);
   set("gender", "男性");
   set("age", 101);
   set("attitude", "friendly");
   set("str", 30);
   set("int", 30);
   set("con", 30);
   set("per", 25);
      
   set("max_kee", 1200);
   set("max_gin", 1000);
   set("max_sen", 1200);
   set("force", 1000);
   set("max_force", 1000);
   set("force_factor", 50);
   set("max_mana", 1200);
   set("mana", 1200);
   set("combat_exp", 500000);

   set_skill("force", 100);
   set_skill("dodge", 100);
   set_skill("unarmed", 100);
   set_skill("parry", 100);
   set_skill("literate", 150);

   set("inquiry", ([
     "name" : "区区正是月老，在此负责天上地下所有的姻缘，已有不知道多少年了。",
     "here" : "这儿就是我办公的地方，所有的姻缘都是我在这儿偷偷牵的线，也是在这儿注册完婚的。",
//     "news" :,
     "结婚" : "想结婚？你要找到你命中注定的那姻缘，然后一起到这里来登记 "HIR"(jiehun) "+NOR"完婚。",
     "登记" : "想结婚？你要找到你命中注定的那姻缘，然后一起到这里来登记 "+HIR"(register) "+NOR"完婚。",
     "离婚" : "唉，世道变了，这年头人心不古，离婚率高得可怕。唉，不管怎样，我也负责处理离婚 "+HIR"(divorce/lihun) "+NOR"申请。",
     "做媒" : "媒人是结婚必不可少的证人，做媒 "+HIR"(zuomei) "+NOR"的负责给女方做证。",
       ]) );

   setup();
}

void init()
{
   add_action("do_register", "register");
   add_action("do_register", "jiehun");
   add_action("do_divorce", "divorce");
   add_action("do_divorce", "lihun");
   add_action("do_zuomei", "zuomei");
}

int do_register()
{
   object me, who, meiren;
   me=this_player();
   message_vision("$N向月下老人打听结婚的事。\n", me);
   if (! interactive(me))
     return 1;
   if (!me->query("waiting_marry")) {
     command("say 咦？我这姻缘簿上没有你的名字呀 ... ..."); 
     command("say 唉，请你先回去，等我给你找到你那姻缘再来吧。");
     return 1;
   }
   if (me->query("gender")=="女性") {
     command("say 嗯，请你的未婚夫上前来。");
     return 1;
   }
   if (!objectp(who=present(me->query("partner"),environment(me)))) {
     command("say 嗯，你的姻缘是有了，可是为什么你的未婚妻没一起来？");
     command("say 请带你的未婚妻到这里来，我才能为你们完成登记手续。");
     return 1;
   }
   if (who->query("partner")!=getuid(me)) {
     command("say 啊？！？你的未婚妻为何又答应另嫁他人了？！？");
     command("say 你们想开什么玩笑？！搞清楚再来！！！");
     return 1;
   }
   if (!who->query("meiren")) {
     command("say 这姻缘嘛，俗话说的好“父母之命，媒妁之言”。这泥潭里无父母，那也罢了。");
     command("say 若再无媒妁之言，那也太不像话了。");
     command("say 你们去找个媒人来吧，由他在此做证，我才能为你们主婚。");
     return 1;
   }
   if (!objectp(meiren=present(who->query("meiren"),environment(me)))) {
     command("say 嗯，你二人都在这儿了，可是那媒人又跑哪儿去啦？");
     command("say 快把媒人找到这儿来，我才能为你们完成登记手续。");
     return 1;
   }

   command("say 哈哈哈哈！好极了，一切齐备，我这就为你们登记！");
   write("月下老人低头把姻缘簿翻了翻，写下些什么。\n");
   command("chat 恭喜，恭喜！");
   command("chat 哈哈哈哈！！！！");
   command("chat "HIM+me->name()+HIC"和"HIM+who->name()+HIC"由"HIY+meiren->name()+HIC"做媒，今日喜结良缘，各位仙友随喜了!!!"NOR);
   command("chat 恭祝两位白头偕老，早生贵子。");

   log_file("yl.rc",me->name()+"和"+who->name()+
     "由"HIY+meiren->name()+NOR"做媒，于"+NATURE_D->game_time()+"("+
     ctime(time())+") 喜结良缘 \n");
    message("shout", HIY "【喜讯通告】：" + HIR + "恭喜" + me->name() + "和" 
         +who->name() + "喜结连理！\n"+"\n"+ HIR
         " 
         ■        ■ 
    ■■■■■■■■■■■
         ■        ■
     ■■■■■■■■■■
       ■■■    ■■■
       ■  ■    ■  ■
       ■■■    ■■■
        ◆◆      ◆◆
     ■■■■■■■■■■
       ■■■    ■■■
       ■  ■    ■  ■
       ■■■    ■■■\n"             
          NOR,users());

   who->delete("waiting_marry");
   who->delete("partner");
   who->delete("meiren");
   who->set("married",1);
   who->set("husband/"+getuid(me), me->name());
   who->set("couple/id", getuid(me));
   who->set("couple/name", me->name());
   me->delete("waiting_marry");
   me->delete("partner");
   me->set("married", 1);
   me->set("wife/"+getuid(who), who->name());
   me->set("couple/id", getuid(who));
   me->set("couple/name", who->name());
   me->set_temp("marrying",1);
   me->set_temp("bride",getuid(who));

   return 1;
}

int do_zuomei(string arg)
{
   object me, who;
   me=this_player();

   if (! interactive(me))
     return 1;
    if (!arg || !objectp(who=present(arg,environment(me)))) {
     tell_object(me,"你要给谁做媒？\n");
     return 1;
   }
   if (arg==me->query("partner")) {
     tell_object(me,"啊？给自己做媒？听说过吗？！？\n");
     return 1;
   }
   if (who->query("gender")=="男性") {
     tell_object(me, "嗯，请媒人为女方做媒。\n");
     return 1;
   }
   if (!who->query("waiting_marry")) {
     tell_object(me,"嗯？这人没打算结婚啊，你瞎起什么哄？！？\n");
     return 1;
   }
   message_vision("$N笑嘻嘻的说：我想给女方做媒。\n", me);
   command("say " + me->query("name") + "原意给" + who->name() + "做媒？");
   command("say 这可是成人之美的善事啊，好极了，我这就记录下来。");
   who->set("meiren", getuid(me));
   return 1;
}

int do_divorce(string arg)
{
   object me,who;
   me=this_player();

   if (! interactive(me))
     return 1;
   if (!arg) {
     tell_object(me, "你打算跟谁离婚？\n");
     return 1;
   }
    if (!me->query("married")) {
     tell_object(me, "你根本没结过婚！\n");
     return 1; }
   if (me->query("gender")=="男性") {
     if (!me->query("wife/"+arg))
        return notify_fail("月下老人奇怪地看了你一眼，道：这人根本不是你妻子！\n");
     if (!(who=find_player(arg))) {
        message_vision("$N冲着月下老人大声嚷嚷着：这日子没法过了，我要离婚！\n", me);
        command("say 对不起，您夫人现在不在线上，不能办理离婚手续");
        return 1; }
     if (!me->query_temp("divorcing")) {
        message_vision("$N冲着月下老人大声嚷嚷着：这日子没法过了，我要离婚！\n", me);
        command("say 唉，你当真想休了你的妻子吗？如果是，请再向我申请一次。");
        me->set_temp("divorcing",1);
        return 1; }
     me->delete("married");
     me->delete("couple");
     me->delete("wife");
     me->delete_temp("divorcing");
     who->delete("married");
     who->delete("couple");
     who->delete("husband");
     tell_object(who, me->name()+"把你休了。");
   }
   else {
     if (!me->query("husband/"+arg))
        return notify_fail("月下老人奇怪地看了你一眼，道：这人根本不是你丈夫！\n");
     if (!(who=find_player(arg))) {
        message_vision("$N冲着月下老人大声嚷嚷着：这日子没法过了，我要离婚！\n", me);
        command("say 对不起，您丈夫现在不在线上，不能办理离婚手续");
        return 1; }
     if (!me->query_temp("divorcing")) {
        message_vision("$N冲着月下老人大声嚷嚷着：这日子没法过了，我要离婚！\n", me);
        command("say 唉，你当真想抛弃你的丈夫吗？如果是，请再向我申请一次。");
        me->set_temp("divorcing",1);
        return 1; }
     who->delete("married");
     who->delete("wife");
     who->delete("couple");
     me->delete("married");
     me->delete("couple");
     me->delete_temp("divorcing");
     me->delete("husband");
     tell_object(who, me->name()+"抛弃了你，不知是跟谁私奔去了。");
   }
   command("say 唉 ... ...");
   command("chat 唉 ... 从今天起，"+me->name()+"和"+who->name()+"就不再是夫妻了。");
   command("chat 又一桩失败的婚姻，唉 ... ... ");
            message("shout", HIY "【离婚通告】：" + HIB + "从现在起" HIM+ me->name() +HIB "和"HIM 
         +who->name() +HIB "婚姻关系解除！\n" NOR,users());        


        log_file("yl.rc",me->name()+"和"+who->name()+
      "于"+NATURE_D->game_time()+"("+ctime(time())+")离婚 \n");

   return 1;
}

