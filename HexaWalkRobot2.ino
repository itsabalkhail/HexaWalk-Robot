#include <Servo.h>

// إنشاء 6 كائنات servo
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

void setup() {
  // ربط servo motors بالمنافذ الرقمية
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);
  servo6.attach(11);
  
  Serial.begin(9600);
  Serial.println("Starting servo control system");
  
  // تشغيل مثال Sweep لمدة ثانيتين
  sweepExample();
  
  // بعد ذلك، جعل جميع المحركات تثبت على 90 درجة
  holdAt90Degrees();
  
  Serial.println("Starting walking motion...");
}

void loop() {
  // تنفيذ خوارزمية المشي
  walkingMotion();
}

// دالة تنفيذ مثال Sweep لمدة ثانيتين
void sweepExample() {
  Serial.println("Running Sweep example for 2 seconds...");
  
  // تشغيل حركة sweep لمدة ثانيتين تقريباً
  for (int cycle = 0; cycle < 2; cycle++) {
    // حركة من 0 إلى 180 درجة
    for (int pos = 0; pos <= 180; pos += 5) {
      servo1.write(pos);
      servo2.write(pos);
      servo3.write(pos);
      servo4.write(pos);
      servo5.write(pos);
      servo6.write(pos);
      delay(50);
    }
    
    // حركة من 180 إلى 0 درجة
    for (int pos = 180; pos >= 0; pos -= 5) {
      servo1.write(pos);
      servo2.write(pos);
      servo3.write(pos);
      servo4.write(pos);
      servo5.write(pos);
      servo6.write(pos);
      delay(50);
    }
  }
}

// دالة لجعل جميع المحركات تثبت على 90 درجة
void holdAt90Degrees() {
  Serial.println("Setting all motors to 90 degrees...");
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);
  servo5.write(90);
  servo6.write(90);
  delay(1000); // انتظار ثانية واحدة
}

// خوارزمية حركة المشي للروبوت الإنساني
void walkingMotion() {
  // الخطوة 1: رفع الساق اليمنى
  Serial.println("Step 1: Lifting right leg");
  servo1.write(45);  // ورك يمين - رفع
  servo2.write(135); // ركبة يمين - ثني
  servo3.write(90);  // كاحل يمين - مستقيم
  delay(500);
  
  // الخطوة 2: تحريك الساق اليمنى للأمام
  Serial.println("Step 2: Moving right leg forward");
  servo1.write(120); // ورك يمين - للأمام
  servo2.write(90);  // ركبة يمين - فرد
  servo3.write(90);  // كاحل يمين - مستقيم
  delay(500);
  
  // الخطوة 3: وضع الساق اليمنى على الأرض
  Serial.println("Step 3: Placing right leg down");
  servo1.write(90);  // ورك يمين - وضع طبيعي
  servo2.write(90);  // ركبة يمين - فرد
  servo3.write(60);  // كاحل يمين - ملامس للأرض
  delay(500);
  
  // الخطوة 4: رفع الساق اليسرى
  Serial.println("Step 4: Lifting left leg");
  servo4.write(135); // ورك يسار - رفع
  servo5.write(45);  // ركبة يسار - ثني
  servo6.write(90);  // كاحل يسار - مستقيم
  delay(500);
  
  // الخطوة 5: تحريك الساق اليسرى للأمام
  Serial.println("Step 5: Moving left leg forward");
  servo4.write(60);  // ورك يسار - للأمام
  servo5.write(90);  // ركبة يسار - فرد
  servo6.write(90);  // كاحل يسار - مستقيم
  delay(500);
  
  // الخطوة 6: وضع الساق اليسرى على الأرض
  Serial.println("Step 6: Placing left leg down");
  servo4.write(90);  // ورك يسار - وضع طبيعي
  servo5.write(90);  // ركبة يسار - فرد
  servo6.write(120); // كاحل يسار - ملامس للأرض
  delay(500);
  
  // الخطوة 7: العودة للوضع الطبيعي
  Serial.println("Step 7: Return to neutral position");
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);
  servo5.write(90);
  servo6.write(90);
  delay(1000);
  
  Serial.println("Walking cycle completed. Repeating...");
}