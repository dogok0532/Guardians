package console_server;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Random;

public class console_server {
	public static void main(String[] args) {
	   
    ServerSocket serversocket = null;
    Socket socket = null;
    while(true) {
    try {
       serversocket = new ServerSocket(9511); //포트번호 : 9511
       socket = serversocket.accept(); // 접속 대기 
       System.out.println("연결 성공");
       Thread thread2 = new receiverthread(socket); // 접속을 받으면 
       thread2.start();// 아래 쓰레드 하나 동작시키고 다시 새로운 접속 대기 
    } catch (Exception e1) {

    } finally {
       try {
          serversocket.close(); // 반복문이 만약 끝나면 소켓 차단, 여기까지 갈 일 없음 
       } catch (Exception e1) {
      	 
       }
    }
    }
 }
}


class receiverthread extends Thread {
 Socket socket; // 정보를 받을 소켓 하나 대기 

 receiverthread(Socket socket) {
    this.socket = socket; // 위의 메인에서 보내 준 소켓을 가져옴.
 }

 @SuppressWarnings("static-access") // 스태틱변수를 그냥 바로써서 나오는 노란밑줄 보기싫어서 씀.
public void run() {
	 player player = new player(); // player 클래스 객체 생성 
	 String a[] = new String[3]; // 키 값을 받아와 판단할 배열 생성 
    try {
    	// 소켓에 들어있는 한줄로 전송되어 오는 데이터를 받아들이기위한 변수 선언.
       BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
       
       // 데이터를 전송할 때 내보내기 위한 변수 선언.
      OutputStream out = socket.getOutputStream();
      
     String str1 = in.readLine(); //str1변수에 소켓에 담긴 데이터를 받아온다.
     a = str1.split(" ");// 띄어쓰기를 기준으로 a 배열에 나누어서 저장한다.
     System.out.println(str1); // 들어온 데이터 확인을 위한 한줄.
     
     if(a[0].equals("xy")) { // 만약 배열 첫 번째 값(키값) 이 xy라면. 아래 반복문 실행.
       while (true) { // 이 반복문은 키값이 xy 인것만 처리한다.
          String str = in.readLine(); // 받아온 소켓에 있는 정보를 str 에 저장.
          player.setXY(str = str.substring(3)); //player객체에 가져온 것을 저장한다. 
          System.out.println(player.getXY()); //객체에 저장되었는 지 확인을 위한 한줄.

          if (str == null) // 소켓에 들어있는 값이 null일때(즉, 접속이 끊겼을 때)
             break; // 반복문 탈출 
          //out.write(str.getBytes()); // 이 서버에 접속된 모든 클라이언트에 데이터 전달. 키값과 같이 보내주자.
       }
     }
    } catch (Exception e1) {

    } finally {
       try {
          socket.close();
       } catch (Exception e1) {

       }

    }

 }

}