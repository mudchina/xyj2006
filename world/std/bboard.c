// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */

// modified by bear
 
// bboard.c

#include <ansi.h>

#define BOARD_CAPACITY query("capacity")
string query_master();
//string *color=({"GRN","RED","HIR","HIG","HIB","HIC","HIM","HIW","HIY"});

inherit ITEM;
inherit F_SAVE;

void setup()
{
   string loc;

   if( stringp(loc = query("location")) )
     move(loc);
   set("no_get", 1);
   seteuid(getuid());
   restore();
}

void init()
{
    if(this_player()->visible(this_object())) {
   add_action("do_post", "post");
   add_action("do_re","re");
   add_action("do_read", "read");
   add_action("do_discard", "discard");
   add_action("do_document", "document");
   add_action("do_appoint","appoint");
   add_action("do_demit","demit");
    }
}

string query_save_file()
{
   string id;

   if( !stringp(id = query("board_id")) ) return 0;
   return DATA_DIR + "board/" + id;
}

string short()
{
   mapping *notes;
   int i, unread, last_read_time;

   notes = query("notes");
   if( !pointerp(notes) || !sizeof(notes) )
     return ::short() + " [ Ã»ÓĞÈÎºÎÁôÑÔ  ±¾°å°åÖ÷£º"+HIY+query_master()+NOR+"]";

   if( this_player() ) {
     last_read_time = (int)this_player()->query("board_last_read/" + (string)query("board_id"));
     for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
        if( notes[i]["time"] <= last_read_time ) break;
   }
   if( unread )
     return sprintf("%s [ [32m%d[m ÕÅÁôÑÔ£¬[1;36m%d[m ÕÅÎ´¶Á  ±¾°å°åÖ÷£º"+HIY+query_master()+NOR+"]", ::short(), sizeof(notes), unread);
   else
     return sprintf("%s [ [32m%d[m ÕÅÁôÑÔ  ±¾°å°åÖ÷£º"+HIY+query_master()+NOR+"]", ::short(), sizeof(notes));
}

string query_master()
{
        if( query("master") )
                return query("master");
        else
                return "áçÇóÖĞ";
}

string long()
{
   mapping *notes;
   int i, last_time_read;
   string msg, myid;

   notes = query("notes");
   msg=sprintf("[1;44m°æÖ÷£º%-10s              %-20s                        [m\n",
                query_master(),query("name"));

   if( !pointerp(notes) || !sizeof(notes) ) return query("long");

   last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));

   for(i=sizeof(notes)-1; i>=0; i--)
     msg += sprintf("%3d %s %s %-25s %s %s\n",
       i+1, ( notes[i]["time"] > last_time_read ? "N": " "),
       ctime(notes[i]["time"])[4..9],notes[i]["author"], notes[i]["sx"],
notes[i]["title"]);
msg+="[1;44m»¶Ó­¹âÁÙÎ÷ÓÎ¼Ç2006                             ±¾Õ¾µØÖ·£º202.103.95.168 6666[m\n";

   return msg;
}

string hostname(object ob)
{
        ob = this_player();

        if( ob->query_host_name() )
        {
                if( ob->query("env/hostname") )
                return ob->query("env/hostname")+ob->query_host_name();
                return ob->query_host_name();
        }

        else
        {
                if( ob->query("env/hostname") )
                return ob->query("env/hostname")+".DTXY.net";
                return ob->query("id")+".DTXY.net";
        }
}

// This is the callback function to process the string returned from the
// editor defined in F_EDIT of player object.

void done_post(object me, mapping note, string text)
{
   mapping *notes;

   note["msg"] = text;
   note["time"] = time();
   notes = query("notes");
   if( !pointerp(notes) || !sizeof(notes) )
     notes = ({ note });
   else
     notes += ({ note });

   // Truncate the notes if maximum capacity exceeded.
   if( sizeof(notes) > BOARD_CAPACITY )
     notes = notes[BOARD_CAPACITY / 5 .. BOARD_CAPACITY];

   set("notes", notes);
   tell_object(me, "ÁôÑÔÍê±Ï¡£\n");

   save();
   return;
}

int do_post(string arg)
{
   mapping note;
    object me;

   me = this_player();
   if(!wizardp(me) && environment(me)->query("post_limit"))
      return notify_fail("Ö»ÓĞÎ×Ê¦²Å¿ÉÒÔÔÚÕâÀïÁôÑÔ¡£\n");

   if(!arg) return notify_fail("ÁôÑÔÇëÖ¸¶¨Ò»¸ö±êÌâ¡£\n");
   if(strlen(arg) > 20 ) return notify_fail("±êÌâÌ«³¤£¡\n");
   
   note = allocate_mapping(5);
   note["title"] = arg;
   note["sx"] = "¡ô";
   note["author"] = this_player()->query("name")+
    "("+capitalize(this_player()->query("id"))+")";
   note["time"] = time();
   note["ip"] = hostname(this_player());
   this_player()->edit( (: done_post, this_player(), note :) );
   return 1;
}

int do_re(string arg)
{
   mapping note;
    object me;
   mapping *notes;
   notes=query("notes");

   me = this_player();
   if(!wizardp(me) && environment(me)->query("post_limit"))
      return notify_fail("Ö»ÓĞÎ×Ê¦²Å¿ÉÒÔÔÚÕâÀïÁôÑÔ¡£\n");

   if(!arg) return notify_fail("ÄãÒªReÄÄÆªÎÄÕÂ£¿\n");
   if(!intp(atoi(arg)) ) return notify_fail("ÄãÖ»ÄÜRe¾ßÌåµÄÄÄÒ»ÆªÎÄÕÂ£¬ÓÃre Êı×Ö±íÊ¾\n");
   if(atoi(arg) > sizeof(notes) ) return notify_fail("Ã»ÓĞÕâÆªÎÄÕÂ£¡\n");

   note = allocate_mapping(5);
   note["title"] = notes[atoi(arg)-1]["title"];
   note["author"] = this_player()->query("name")+
    "("+capitalize(this_player()->query("id"))+")";
   note["time"] = time();
   note["sx"] = "[1;32mRe[m";
   note["ip"] = hostname(this_player());
   this_player()->edit( (: done_post, this_player(), note :) );
   return 1;
}

int do_appoint(string arg)
{
        object me = this_player();

   if( (string)SECURITY_D->get_status(this_player(1)) != "(admin)"
    && (string)SECURITY_D->get_status(this_player(1)) !="(arch)"
    && (string)SECURITY_D->get_status(this_player(1)) !="(wizard)" )
    return notify_fail("ÄãÃ»ÓĞÈÎÃâ°æÖ÷µÄÈ¨Àû!\n");
    
    if( !arg)
        return notify_fail("ÄãÒªÈÎÃâË­Îª±¾°æ°æÖ÷£¿\n");

    if( !present(arg,environment(me) ) )
        return notify_fail("ÄãÒªÈÎÃüµÄÍæ¼Ò²»ÔÚÕâ¸öµØ·½£¡\n");

    if(this_object()->query("master") )
                return notify_fail("Õâ¸ö°æÒÑ¾­ÓĞ°æÖ÷ÁË£¡\n");

    this_object()->set("master",arg);
    message("system",HIR"¡¾¹«¸æ¡¿£ºÈÎÃü "+arg+" Îª"+this_object()->name()+"°åÖ÷£¡\n"NOR,users());
    save();      
  return 1;
}

int do_demit()
{
        object me = this_player();

   if( (string)SECURITY_D->get_status(this_player(1)) != "(admin)"
    && (string)SECURITY_D->get_status(this_player(1)) !="(arch)"
    && (string)SECURITY_D->get_status(this_player(1)) !="(wizard)" )
    return notify_fail("ÄãÃ»ÓĞÈÎÃâ°æÖ÷µÄÈ¨Àû!\n");


    if(!this_object()->query("master") )
                return notify_fail("Õâ¸ö°æ±¾À´¾ÍÃ»ÓĞ°æÖ÷£¡\n");
    message("system",HIR"¡¾¹«¸æ¡¿£º°ÕÃâ"+this_object()->name()+"°åÖ÷ "+ this_object()->query("master") +" £¡\n"NOR,users());
    this_object()->delete("master");
    save();
  return 1;
}
    
int do_read(string arg)
{
   int num;
   mapping *notes, last_read_time;
   string myid;

   last_read_time = this_player()->query("board_last_read");
   myid = query("board_id");
   notes = query("notes");

   if( !pointerp(notes) || !sizeof(notes) )
     return notify_fail("ÁôÑÔ°åÉÏÄ¿Ç°Ã»ÓĞÈÎºÎÁôÑÔ¡£\n");

   if( !arg ) return notify_fail("Ö¸Áî¸ñÊ½£ºread <ÁôÑÔ±àºÅ>|new|next\n");
   if( arg=="new" || arg=="next" ) {
     if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
        num = 1;
     else
        for(num = 1; num<=sizeof(notes); num++)
          if( notes[num-1]["time"] > last_read_time[myid] ) break;
        
   } else if( !sscanf(arg, "%d", num) )
     return notify_fail("ÄãÒª¶ÁµÚ¼¸ÕÅÁôÑÔ£¿\n");

   if( num < 1 || num > sizeof(notes) )
     return notify_fail("Ã»ÓĞÕâÕÅÁôÑÔ¡£\n");
   num--;

this_player()->start_more( sprintf(
"[47;34m  ×÷Õß [44;37m %-20s                    [47;34m  ÌÖÂÛÇø  [37;44m%20s
[47;34m  ±êÌâ [44;37m %-70s
[47;34m  Ê±¼ä [44;37m %-70s[m  [36m\n------------------------------------------------------------------------------[m\n\n\n",
notes[num]["author"],name(),notes[num]["title"],ctime(notes[num]["time"]))
+ notes[num]["msg"] +
sprintf("\n\n\n[1;32m¡ù Origin : [33mÎ÷ÓÎ¼Ç2006×ÜÕ¾ [37m< 202.103.95.168 6666 >
[31m¡Ñ From : %-70s[m", notes[num]["ip"]));


   // Keep track which post we were reading last time.
   if( !mapp(last_read_time) )
     this_player()->set("board_last_read", ([ myid: notes[num]["time"] ]) );
   else 
     if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
        last_read_time[myid] = notes[num]["time"];

   return 1;
}


int do_discard(string arg)
{
   mapping *notes;
   int num;

   if( !arg || sscanf(arg, "%d", num)!=1 )
     return notify_fail("Ö¸Áî¸ñÊ½£ºdiscard <ÁôÑÔ±àºÅ>\n");
   notes = query("notes");
   if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
     return notify_fail("Ã»ÓĞÕâÕÅÁôÑÔ¡£\n");
   num--;
   if( notes[num]["author"] != 
     (string) this_player(1)->query("name")+
     "("+capitalize(this_player(1)->query("id"))+")"
   && (string)SECURITY_D->get_status(this_player(1)) !="(arch)"
   &&   (string)SECURITY_D->get_status(this_player(1)) != "(admin)" 
   &&  this_object()->query("master") != this_player(1)->query("id") 
)

     return notify_fail("ÄãÎŞÈ¨É¾³ıÕâ¸öÁôÑÔ£¡\n");

   if (num >0)
             notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
        else
          notes =notes[num+1..sizeof(notes)-1];
   set("notes", notes);
   save();
   write("É¾³ıµÚ " + (num+1) + " ºÅÁôÑÔ....Ok¡£\n");
   return 1;
}


int do_document(string arg)
{
        object document, content, cont_num;
   string mon, dirname="/data/";
   int month, num, nummonth, defmon, defyear, argn;
        mapping *notes;
   string *strmon=({"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"});

   if( (string)SECURITY_D->get_status(this_player(1)) != "(admin)"
    && (string)SECURITY_D->get_status(this_player(1)) !="(arch)" 
    && (string)SECURITY_D->get_status(this_player(1)) !="(wizard)" )
     return notify_fail("ÄãÃ»ÓĞ´æµµµÄÈ¨Á¦£¡\n");

//by mon. 9/6/97
        if(environment(this_player())->query("wiz_board"))
     dirname+="wiz_doc/";
        else
     dirname+="doc/";

   argn=sscanf(arg, "%d %d %d", num, defmon, defyear);

        if(!arg || argn >3)
                return notify_fail("Ö¸Áî¸ñÊ½£ºdocument <ÁôÑÔ±àºÅ>\n");

   if (argn==3) {
     dirname = dirname + sprintf("%d",defyear)+"/";
     month=defmon;
     mon="Null";
     }
   if (argn==2) {
     if (defmon>1995) {
        dirname = dirname + sprintf("%d",defmon)+"/";    
        mon=ctime(time())[4..6];
        }
     else {
        dirname = dirname + ctime(time())[20..23] + "/";
        month=defmon;
        mon="Null";
        }
     }
   if (argn==1) {
     dirname = dirname + ctime(time())[20..23] + "/";
     mon=ctime(time())[4..6];
     }
   if ( mon=="Null" ) {
     if (month>12 || month<1) return notify_fail("Òª´æµÄÔÂ·İ²»´æÔÚ£¡\n");
     mon=strmon[month-1];
     }
   else switch (mon) {
     case "Jan": month=1; break;
                case "Feb": month=2; break;
                case "Mar": month=3; break;
                case "Apr": month=4; break;
                case "May": month=5; break;
                case "Jun": month=6; break;
                case "Jul": month=7; break;
                case "Aug": month=8; break;
                case "Sep": month=9; break;
                case "Oct": month=10; break;
                case "Nov": month=11; break;
                case "Dec": month=12; break;
     }

   if (month>12 || month<1) return notify_fail("Òª´æµÄÔÂ·İ²»´æÔÚ£¡\n");


   notes = query("notes");
   if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
     return notify_fail("Ã»ÓĞÕâÕÅÁôÑÔ¡£\n");
   num--;

   cont_num=new("/obj/not.c");
   cont_num->set("file_name", dirname+"month.number");
        cont_num->restore();

   if (!objectp(cont_num) )
                return notify_fail("ÎÄµµ¶ÁÈ¡Ê§°Ü£¡\n");
   nummonth=cont_num->query(mon);
   nummonth++;
   cont_num->set(mon, nummonth);
   if (!cont_num->save())
     return notify_fail("´æµµÊ§°Ü£¡\n");

   content=new("/obj/not.c");
   content->set("file_name", dirname+"content."+mon);
   content->restore();
   if ( !objectp(content) )
     return notify_fail("ÎÄµµ¶ÁÈ¡Ê§°Ü£¡\n");
   if (content->query("msg")) content->set("msg", content->query("msg")+ 
sprintf("[%3d] %-40s %12s (%s)\n",
nummonth, notes[num]["title"], notes[num]["author"], ctime(notes[num]["time"])[0..9])
);
   else content->set("msg", sprintf("[%3d] %-40s %12s (%s)\n",nummonth, notes[num]["title"], notes[num]["author"], ctime(notes[num]["time"])[0..9]));

   if (!content->save())
                return notify_fail("´æµµÊ§°Ü£¡\n");

   document=new("/obj/not.c");
   document->set("file_name", dirname+ sprintf("%s/doc%d.%d",mon,month, nummonth) );
   document->restore();
   if ( !objectp(document) )
     return notify_fail("ÎÄµµ¶ÁÈ¡Ê§°Ü£¡");
   document->set("msg",
sprintf("[%3d] %-40s %12s (%s)\n--------------------------------------------------------------------------------\n", nummonth, notes[num]["title"], notes[num]["author"], ctime(notes[num]["time"])[0..9])
+ notes[num]["msg"]
);
   if (!document->save())
     return notify_fail("´æµµÊ§°Ü£¡\n");
   write("OK.\n");
   
/*
   if (num >0)
             notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
        else
          notes =notes[num+1..sizeof(notes)-1];
        set("notes", notes);
        save();
*/
   return 1;
}   
