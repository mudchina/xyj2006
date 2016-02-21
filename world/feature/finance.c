          // finance.c
// mon 12/31/96

// can_afford() checks if this_object() can afford a price, it returns:
//
//      0:      cannot afford.
//      1:      can afford with proper money(coins).
//      2:      can afford, but don't have enough proper money(coins).
//
int can_afford(int amount)
{
        int total, cash_value;
        object cash, gold, silver, coin, me=this_player();

        cash = present("thousand-cash_money",me);
        gold = present("gold_money",me);
        silver = present("silver_money",me);
        coin = present("coin_money",me);

        total = 0;
        cash_value = 0;
        if( cash ) cash_value = cash->value();
        if( gold ) total += gold->value();
        if( silver ) total += silver->value();
        if( coin ) total += coin->value();

        if( (cash_value + total) < amount ) return 0;
        if( total < amount ) return 2;
        //if( total < amount ) return 0;

/*
        if( coin ) amount -= (int)coin->value();
        if( amount <= 0 ) return 1;
        else if( amount % 100 ) return 2;

        if( silver ) amount -= (int)silver->value();
        if( amount <= 0 ) return 1;
        else if( amount % 10000 ) return 2;
*/
        return 1;
}

int pay_money(int amount)
{
        int total;
        object gold, silver, coin, me=this_player();
        int goldno, silverno, coinno;

        gold = present("gold_money",me);
        silver = present("silver_money",me);
        coin = present("coin_money",me);

        total = 0;
        if( gold ) total += gold->value();
        if( silver ) total += silver->value();
        if( coin ) total += coin->value();

        if( total < amount ) return 0;
        
        total -= amount;
        goldno = total/10000;
        silverno = (total % 10000) / 100;
        coinno = total % 100;

        if (!coin && coinno>0) 
           coin=new("/obj/money/coin");
        if (coin) coin->set_amount(coinno);
        if (coinno>0) coin->move(me);
        if ( coinno == 0 && coin) destruct(coin);

        if (!silver && silverno>0) 
           silver=new("/obj/money/silver");
        if (silver) silver->set_amount(silverno);
        if (silverno>0) silver->move(me);
        if (silverno == 0 && silver) destruct(silver);
   
        if (!gold && goldno>0) 
           gold=new("/obj/money/gold");
        if (gold) gold->set_amount(goldno);
        if (goldno>0) gold->move(me);
        if (goldno == 0 && gold) destruct(gold);

        me->save();
        return 1;
}


