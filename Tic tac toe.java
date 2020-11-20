import java.util.*;
class Dcoder
{
    
  public static boolean check(String board[] ){

          for( int i = 0 ; i < 7 ;i++ ){
            if(board[i].charAt(1) == 'X' && board[i].charAt(3) == 'X' && board[i].charAt(5) == 'X'){
                        return true;
                    }
       else if(board[i].charAt(1) == 'O' && board[i].charAt(3) == 'O' && board[i].charAt(5) == 'O'){
                        return true;
                    }
          }
            for( int i = 0 ; i < 7 ;i++ ){
          if(board[1].charAt(i) == 'X' && board[3].charAt(i) == 'X' &&board[5].charAt(i) == 'X'){
             return true; 
          }
          else if(board[1].charAt(i) == 'O' && board[3].charAt(i) == 'O' &&board[5].charAt(i) == 'O'){
              return true;
          }
            }
        if(board[1].charAt(1) == 'X' && board[3].charAt(3) == 'X' &&board[5].charAt(5) == 'X'){
             return true; 
          }
        else if(board[1].charAt(1) == 'O' && board[3].charAt(3) == 'O' &&board[5].charAt(5) == 'O'){
             return true; 
          }
        else if(board[1].charAt(5) == 'X' && board[3].charAt(3) == 'X' &&board[5].charAt(1) == 'X'){
             return true; 
          }
        else if(board[1].charAt(5) == 'O' && board[3].charAt(3) == 'O' &&board[5].charAt(1) == 'O'){
             return true; 
          }
      return false;
  }
  public static void main(String args[]){
      Scanner sc = new Scanner(System.in);
  String board[] = new String[7]; 
           board[0] =  "-------";
           board[1] =  "|1|2|3|";
           board[2] =  "-------";
           board[3] =  "|4|5|6|";
           board[4] =  "-------";
           board[5] =  "|7|8|9|";
           board[6] =  "-------";
      int y =0;
      again:while(true){
          for( int i = 0 ; i < 7 ;i++ ){
          for( int j = 0 ; j < 7 ; j++ ){    
          System.out.printf("%c",board[i].charAt(j));
          }
           System.out.println();
          }
          char s;
          if( y % 2 == 0)
          s = 'X';
          else
          s = 'O';
          System.out.println("Move for " + s);
          y++;
          int x = sc.nextInt();
               if( x == 1 && board[1].charAt(1) != 'X' && board[1].charAt(1) != 'O' )
              board[1] = board[1].substring(0, 1)+ s + board[1].substring(2);
          else if( x == 2 && board[1].charAt(3) != 'X' && board[1].charAt(3) != 'O' )
              board[1] = board[1].substring(0, 3)+ s + board[1].substring(4);
          else if( x == 3 && board[1].charAt(5) != 'X' && board[1].charAt(5) != 'O' )
              board[1] = board[1].substring(0, 5)+ s + board[1].substring(6);
          else if( x == 4 && board[3].charAt(1) != 'X' && board[3].charAt(1) != 'O' )
              board[3] = board[3].substring(0, 1)+ s + board[3].substring(2);
          else if( x == 5 && board[3].charAt(3) != 'X' && board[3].charAt(3) != 'O' )
              board[3] = board[3].substring(0, 3)+ s + board[3].substring(4);
          else if( x == 6 && board[3].charAt(5) != 'X' && board[3].charAt(5) != 'O' )
              board[3] = board[3].substring(0, 5)+ s + board[3].substring(6);
          else if( x == 7 && board[5].charAt(1) != 'X' && board[5].charAt(1) != 'O' )
              board[5] = board[5].substring(0, 1)+ s + board[5].substring(2);
          else if( x == 8 && board[5].charAt(3) != 'X' && board[5].charAt(3) != 'O' )
              board[5] = board[5].substring(0, 3)+ s + board[5].substring(4);
          else if( x == 9 && board[5].charAt(5) != 'X' && board[5].charAt(5) != 'O' )
              board[5] = board[5].substring(0, 5)+ s + board[5].substring(6);
          else{
              System.out.println("Illigal move\nGive move again");
              y--;
              continue again;
          }
          if(check(board) == true){
              System.out.println(s + " is winner");
              break;
       }
  }
}
}
