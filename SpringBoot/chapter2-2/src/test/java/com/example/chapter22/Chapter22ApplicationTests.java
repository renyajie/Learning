package com.example.chapter22;

import com.example.chapter22.domain.UserController;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.http.MediaType;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.RequestBuilder;
import org.springframework.test.web.servlet.setup.MockMvcBuilders;

import static org.hamcrest.Matchers.equalTo;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.*;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.*;

@SpringBootTest
class Chapter22ApplicationTests {

    private MockMvc mock;

    @Test
    void contextLoads() {
    }

    @BeforeEach
    void setup() {
        mock = MockMvcBuilders.standaloneSetup(new UserController()).build();
    }

    @Test
    public void testUserController() throws Exception {
        RequestBuilder request;

        // 1.查一下user列表，应该为空
        request = get("/user/"); // 注意：如果只有一个user，后面的/不能省略
        mock.perform(request)
                .andExpect(status().isOk())
                .andExpect(content().string(equalTo("[]")));

        // 2.post提交一个user
        request = post("/user/")
                .contentType(MediaType.APPLICATION_JSON)
                .content("{\"id\":1,\"name\":\"ryj\",\"age\":20}");
        mock.perform(request)
                .andExpect(status().isOk())
                .andExpect(content().string(equalTo("success")));

        // 3. get获取刚才的user列表，应该有刚才的数据
        request = get("/user/");
        mock.perform(request)
                .andExpect(status().isOk())
                .andExpect(content().string(equalTo("[{\"id\":1,\"name\":\"ryj\",\"age\":20}]")));

        // 4. 修改id为1的用户，名字改一下
        request = put("/user/1")
                .contentType(MediaType.APPLICATION_JSON)
                .content("{\"id\":1,\"name\":\"xls\",\"age\":20}");
        mock.perform(request)
                .andExpect(status().isOk())
                .andExpect(content().string(equalTo("success")));

        // 5. 查询刚才的修改信息，名字是否已经修改好了
        request = get("/user/1");
        mock.perform(request)
                .andExpect(status().isOk())
                .andExpect(content().string(equalTo("{\"id\":1,\"name\":\"xls\",\"age\":20}")));

        // 6. 删除id为1的用户
        request = delete("/user/1");
        mock.perform(request)
                .andExpect(status().isOk())
                .andExpect(content().string(equalTo("success")));

        // 7. 查询用户列表，应该为空
        request = get("/user/");
        mock.perform(request)
                .andExpect(status().isOk())
                .andExpect(content().string(equalTo("[]")));
    }
}
