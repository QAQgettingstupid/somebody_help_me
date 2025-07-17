import 'package:flutter/material.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(title: const Text('i am text'),),
        body: Column(
          children: [
            Container(
              color: Colors.yellow,
            )
          ],
        ),
      ),
    );
  }
}
