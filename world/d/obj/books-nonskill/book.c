// book.c: a file that all non-skill books will inherit
// created 9-26-97 pickle

#include "book.h";

mapping toberead=([]);

int read_book(object me,string name)
{
        object obj,ob;
        int fuyuan,chance,fuyuanchance;
	obj=this_object(); 
  	fuyuan = (int)me->query_kar();
  	chance = random(1000);
  	fuyuanchance = (fuyuan * fuyuan);

      //    checks if the book's been read too many times.
      //    avoids abuse by players to keep reading the same book with a robot
      //    another layer of protection is that the bookstore only sells 30
      //    books each refresh, which means that a player has 90 times to try
      //    at getting something. and the chance of getting a guo is, for the
      //    player with the best fuyuan, about 1 per refresh.

  if (toberead[name] == 3) 
    {
      message_vision("只见" + obj->query("name") + "化成片片碎屑，从$N的手中飘落。\n", me);
      call_out("destroy", 1, obj);
      tell_object(me, "书已经被翻烂了，换一本新的吧！\n");
      return 1;
 }

//     if passes check then test what the player may get
//     first checks for guo, 10% times the kar squared / 100000
//     so for kar 30, 10% times 9/100 or about 1%
//     and for kar 10, only 0.1%

  if ((chance < 10) && (random(100)*100 < fuyuanchance))
    {message_vision(GRN "$N拿起一本"+ obj->query("name")+"，只觉书本沉甸甸的，连忙翻开。\n" NOR, me);
     message_vision(GRN "书中飘出一张纸条，上写：书中自有千锺粟。\n", me);
     message_vision(GRN "$N低头一看，居然从书里落下一枚淡绿色的丹药！\n", me);
     message_vision(GRN "$N弯下腰，捡起了丹药，却一不小心，把书掉在水坑里了。\n" NOR, me);
     ob = new("/d/obj/drug/guo");
     ob->move(me);
        call_out("destroy", 1, obj);
     return 1;
    }
//    if doesn't get guo, then check for tao.
//    tao is at similar chance. 10% times kar/1000
//    if kar is 30, then about 0.3% chance.
//    if kar is 10, then only 0.1% chance again.

  if ((chance < 10) && (random(100)*10 < fuyuan))
    {message_vision(YEL "$N拿起一本"+ obj->query("name")+"，只觉书本沉甸甸的，连忙翻开。\n" NOR, me);
     message_vision(YEL "书中飘出一张纸条，上写：书中自有千锺粟。\n", me);
     message_vision(YEL "$N低头一看，居然从书里落下一颗猕猴桃！\n", me);
     message_vision(YEL "$N弯下腰，捡起了猕猴桃，却一不小心，把书掉在水坑里了。\n" NOR, me);
     ob = new("/d/obj/drug/mihoutao");
     ob->move(me);
        call_out("destroy", 1, obj);
     return 1;
    }

//    if still not, then checks for gold.
//    20% times kar/100, which is quite generous. =}
//    kar 30 means 15%, kar 10 means 5%.

  if ((chance < 10) && (random(100)*5 < fuyuan))
    {message_vision(HIY "$N拿起一本"+ obj->query("name")+"，只觉书本沉甸甸的，连忙翻开。\n" NOR, me);
     message_vision(HIY "书中飘出一张纸条，上写：书中自有黄金屋。\n", me);
     message_vision(HIY "只听「当」的一声，居然从书里落下一两黄金！\n", me);
     message_vision(HIY "$N弯下腰，捡起了金子，却一不小心，把书掉在水坑里了。\n" NOR, me);
     ob = new("/obj/money/gold");
     ob->move(me);
        call_out("destroy", 1, obj);
     return 1;
   }
  write("\n");
  this_player()->start_more(read_file("/d/obj/books-nonskill/text/"+name));
  toberead[name]++;
  return 1;
}

void destroy(object obj)
{
        destruct(obj);
        return;
}
