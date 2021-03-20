package com.example.chapter21.web;

import com.example.chapter21.domain.User;
import org.springframework.web.bind.annotation.*;

import java.util.*;
import java.util.stream.Collectors;

@RestController
@RequestMapping("/user")
public class UserController {
    static Map<Long, User> map = Collections.synchronizedMap(new HashMap<Long,User>());

    /**
     * 处理/user的get请求，返回user列表
     * @return
     */
    @GetMapping("/")
    public List<User> getUserList() {
        List<User> res = new ArrayList<>(map.values());
        return res;
    }

    /**
     * 处理/user的post请求
     * @param user 用户信息，这里提交的是json数据，所以用@RequestBody注解转化一下
     * @return
     */
    @PostMapping("/")
    public String postUser(@RequestBody User user) {
        map.put(user.getId(), user);
        return "success";
    }

    /**
     * 处理/user/id的get请求
     * @param id 用户id
     * @return
     */
    @GetMapping("/{id}")
    public User getUser(@PathVariable Long id) {
        return map.get(id);
    }

    /**
     * 处理/user/id的put请求(更新操作)
     *@param id 用户id
     * @param user 用户信息，这里提交的是json数据，所以用@RequestBody注解转化一下
     * @return
     */
    @PutMapping("/{id}")
    public String putUser(@PathVariable Long id, @RequestBody User user) {
        User u = map.get(id);
        u.setAge(user.getAge());
        u.setName(user.getName());
        map.put(id, u);
        return "success";
    }

    /**
     * 处理/user/id的delete请求
     * @param id 用户id
     * @return
     */
    @DeleteMapping("/{id}")
    public String deleteUser(@PathVariable Long id) {
        map.remove(id);
        return "success";
    }
}
