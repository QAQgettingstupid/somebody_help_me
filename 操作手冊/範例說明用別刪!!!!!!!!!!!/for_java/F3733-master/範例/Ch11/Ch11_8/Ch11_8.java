// Ch11_8, instanceof運算子的使用
class Circle { }
class Coin extends Circle { }     	  // Coin繼承Circle類別
public class Ch11_8 extends Coin{     // Ch11_8繼承Coin類別
   public static void main(String args[]){
      boolean status;
      Coin cn=new Coin();
      Circle c1=new Circle();
      Ch11_8 myobj=new Ch11_8();
      Coin carr[]=new Coin[5];

      // 判別c1是否為CCoin類別或其子類別物件
      status=(c1 instanceof Coin);
      System.out.println("c1 instanceof CCoin? " + status);

      // 判別myobj是否為Circle類別或其子類別物件
      status=(myobj instanceof Circle);
      System.out.println("myobj instanceof Circle? " + status);

      // 判別cn是否為Ch11_8類別或其子類別物件
      status=(cn instanceof Ch11_8);
      System.out.println("cn instanceof Ch11_8? "+ status);

      // 判別cn是否為Circle類別或其子類別物件
      status=(cn instanceof Circle);
      System.out.println("cn instanceof Circle? " + status);

      // 判別cn是否為Coin類別或其子類別物件
      status=(cn instanceof Coin);
      System.out.println("cn instanceof Coin? " + status);

      // 判別陣列是否為Object類別或其子類別物件
      status=(carr instanceof Object);
      System.out.println("carr instanceof Object? " + status);

      // 判別c1是否為String類別或其子類別物件
      // status=(c1 instanceof String);
      // System.out.println("c1 instanceof String? "+ status);
  }
}