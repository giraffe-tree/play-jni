/*
 * Copyright 2018-2019 the original author or authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


/**
 * @author GiraffeTree
 * @date 2018-12-18
 */
public class HelloTransfer {

    static {
        System.load("C:\\Users\\Administrator\\source\\repos\\giraffetree\\jni_list\\x64\\Release\\jni_list.dll");
    }

    public static native void helloTransfer(boolean isTrue, int intValue, long longValue, String name);

    public static void main(String[] args) {
        helloTransfer(false, 1, 2L, "John");
    }

}
