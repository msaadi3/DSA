function time() {
  let date = new Date();
  document.getElementById("cb").innerHTML =
    date.getHours() + ":" + date.getMinutes() + ":" + date.getSeconds();
}

setInterval(time, 1000);

// promises

// let prom = new Promise();
// console.log(prom);

// let promises = new Promise((resolve, reject) => {
//   let x = 1;
//   if (x == 0) {
//     resolve("resolved");
//   } else {
//     reject("rejected due to some errror ");
//   }
// });

// promises.then(function (value) {
//   console.log(value);
// }),
//   function (err) {
//     console.log(err);
//   };

// promises.then(function (value) {
//   console.log(value);
// });
// promises.catch(function (error) {
//   console.log(error);
// });

// function loadScript(cdn, callback) {
//   let script = document.createElement("script");
//   script.src = cdn;
//   script.onload = function () {
//     console.log("script is loaded successfully" + cdn);
//     callback(null, cdn);
//   };
//   script.onerror = function () {
//     console.log("script failed due to some error " + cdn);
//     callback(new Error("src got some src"));
//   };

//   document.body.appendChild(script);
// }

// function callBack(error, cdn) {
//   if (error) {
//     console.log(error);
//     return;
//   }
//   console.log("hello sir your script has been loaded successfully" + cdn);
// }

// loadScript(
//   "https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js",
//   callBack
// );

// let p1 = new Promise((resolve, reject) => {
//   console.log("promise is pending");
//   setTimeout(() => {
//     console.log("resolved promise");
//     resolve(true);
//   }, 5000);
// });
// console.log(p1);
// let p2 = new Promise((resolve, reject) => {
//   console.log("promise is pending");
//   setTimeout(() => {
//     console.log("rejected promise");
//     reject(new Error("error"));
//   }, 5000);
// });
// console.log(p2);
/*let loadScriptWithPromises = function (cdn) {
  return new Promise((resolve, reject) => {
    let script = document.createElement("script");
    script.src = cdn;
    script.onload = resolve("script is loaded successfully" + cdn);
    script.onerror = reject("failed due to some error " + cdn);
  });
};

let p = loadScriptWithPromises(
  "https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js"
);
p.then(
  function (value) {
    console.log(value);
  },
  function (error) {
    console.log(error);
  }
);*/

// students = [
//   { name: "Saad", subject: "javascript" },
//   { name: "aubrey kate", subject: "css" },
//   { name: "jade venus", subject: "reactjs" },
// ];

// function enrollStudent(student, callback) {
//   setTimeout(() => {
//     students.push(student);
//   }, 2000);
//   console.log("student has been enrolled");
//   callback();
// }
// function getStudent() {
//   setTimeout(() => {
//     students.forEach((student) => {
//       console.log(
//         `here are the students name: ${student.name} and what they study now a days ${student.subject}`
//       );
//     });
//   }, 3000);
// }

// let newStudent = { name: "khloe kay", subject: "solidity" };

// enrollStudent(newStudent, getStudent);

// students = [
//   { name: "Saad", subject: "javascript" },
//   { name: "aubrey kate", subject: "css" },
//   { name: "jade venus", subject: "reactjs" },
// ];

// function enrollStudentWithPromises(student) {
//   return new Promise((resolve, reject) => {
//     setTimeout(() => {
//       students.push(student);
//       resolve();
//     }, 1000);
//   });
// }

// function getStudentWithPromises() {
//   return new Promise((resolve, reject) => {
//     setTimeout(() => {
//       students.forEach((element) => {
//         console.log(
//           `student name is ${element.name} and his/her subject is ${element.subject}`
//         );
//         resolve("resolved");
//         reject("error");
//       }, 2000);
//     });
//   });
// }
// let newStudent = { name: "khloe kay", subject: "solidity" };

// enrollStudentWithPromises(newStudent)
//   .then(getStudentWithPromises)
//   .then(
//     (value) => {
//       console.log(value);
//     },
//     (error) => {
//       console.log("some error occured in get function", error);
//     }
//   );

// Promise Chaining

// let promise = new Promise((resolve, reject) => {
//   setTimeout(() => {
//     console.log("hehe");
//     resolve("resolved");
//   }, 1000);
// });

// promise.then((value) => {
//   console.log(value);
//   return new Promise((resolve, reject) => {
//     console.log("another promise");
//     resolve("another one");
//   })
//     .then((result) => {
//       console.log(result);
//       let promiseThird = new Promise((resolve, reject) => {
//         setTimeout(() => {
//           console.log("third promise");
//           resolve("third resolved");
//         }, 3000);
//       });
//       return promiseThird;
//     })
//     .catch((err) => {
//       console.log(err);
//     })
//     .then((resultThird) => {
//       console.log(resultThird);
//       return 2 + 3;
//     })
//     .catch((err) => {
//       console.log(err);
//     })
//     .then((resultFourth) => {
//       console.log(resultFourth);
//     })
//     .catch((err) => {
//       console.log(err);
//     });
// });

// MULTIPLE HANDLERS

// let prom = new Promise((resolve, reject) => {
//   // let x = prompt("enter any number");
//   let x = 1;
//   if (x == 0) {
//     resolve("resolved");
//   } else {
//     reject("rejected");
//   }
//   return prom;
// });
/* why this one is not working 
function prom() {
  return new Promise((resolve, reject) => {
    let x = 0;
    if (x == 0) {
      resolve("resolved");
    } else {
      reject("rejected");
    }
  });
}
*/
// prom
//   .then((result) => {
//     console.log("good job", result);
//   })
//   .catch((err) => {
//     console.log("you should enter only zero", err);
//   });

// prom
//   .then((result) => {
//     console.log("another one then", result);
//   })
//   .catch((err) => {
//     console.log(err);
//   });
// prom
//   .then((result) => {
//     console.log("another one probably third then ", result);
//   })
//   .catch((err) => {
//     console.log(err);
//   });

// Promise API

// let p1 = new Promise((resolve, reject) => {
//   setTimeout(() => {
//     resolve("p1");
//     // reject("p1");
//     // reject(new Error("error object for p1"));
//     console.log("first console log");
//   }, 1000);
// });

// let p2 = new Promise((resolve, reject) => {
//   setTimeout(() => {
//     console.log("second console log");
//     resolve("p2");
//     // reject(new Error("second p2 error"));
//   }, 2000);
// });

// let p3 = new Promise((resolve, reject) => {
//   console.log("third console log");
//   setTimeout(() => {
//     // reject("p3 rejected ");
//     reject(new Error("error object for p3"));
//     // resolve("p3");
//   }, 3000);
// });

// let promiseAll = Promise.all([p1, p2, p3]);
// // console.log(promiseAll);
// promiseAll
//   .then((result) => {
//     console.log(result);
//   })
//   .catch((err) => {
//     console.log("p1 error", err);
//   });

// let allSettledPromise = Promise.allSettled([p1, p2, p3]);
// // console.log(allSettledPromise);
// allSettledPromise.then((value) => {
//   console.log(value);
// });
// let racePromise = Promise.race([p1, p2, p3]);
// // console.log(racePromise);
// racePromise.then(
//   (value) => {
//     console.log(value);
//   },
//   (err) => {
//     console.log("error in p1", err);
//   }
// );

// let anyPromise = Promise.any([p1, p2, p3]);
// // console.log(anyPromise);
// anyPromise
//   .then((result) => {
//     console.log(result);
//   })
//   .catch((err) => {
//     console.log(err);
//   });

// Async Await

// async makes a function return a promise
// await makes a fucntion wait for a promise
// await can only be used inside an async function
// in async await there's no need for .then/.catch to handle errors use try/catch syntax and get resolved value in variable
// async function promise3() {
//   let a = await "hello world";
//   return a;
// }
// // async makes a function return a promise
// promise3().then((a) => {
//   console.log(a);
// });

// function promise3Resolve() {
//   return Promise.resolve("hello world");
// }

// promise3Resolve().then((result) => {
//   console.log(result);
// });

// let promise3Constructor = new Promise((resolve, reject) => {
//   resolve("hello world");
// });

// promise3Constructor.then((result) => {
//   console.log(result);
// });

// function promise5() {
//   return new Promise((resolve, reject) => {
//     setTimeout(() => {
//       let x = 1;
//       if (x == 0) {
//         resolve("true");
//       } else {
//         // reject(new Error("false"));
//         reject("false");
//       }
//     }, 1000);
//   });
// }

// async function asyncPromise5WithCatch() {
//   let result = await promise5().catch((err)=>{console.log(er)})
//   console.log(result.catch((err)=>{console.err}))
// }
// async function asyncPromise5() {
//   try {
//     let result = await promise5();
//     // return result;
//     console.log(result);
//   } catch (error) {
//     console.log(error);
//   }
// }
// asyncPromise5();
// // console.log(asyncPromise5());
// async function hehe() {
//   let promise1 = new Promise((resolve, reject) => {
//     setTimeout(() => {
//       resolve("Hey!! i  m resolved p1");
//     }, 1000);
//   });

//   let promise2 = new Promise((resolve, reject) => {
//     setTimeout(() => {
//       resolve("hey i m resolved p2");
//     }, 2000);
//   });
//   let p1 = await promise1;
//   let p2 = await promise2;
//   return [p1, p2];
//   // console.log(p1, p2);
// }
// console.log(hehe());

// function returnsPromise(x) {
//   return new Promise((resolve, reject) => {
//     setTimeout(() => {
//       resolve(x);
//     }, 1000);
//   });
// }

// const awaitFunction = async function () {
//   let a = await returnsPromise(20);
//   let b = await returnsPromise(30);
//   return a + b;
// };
// awaitFunction().then((v) => {
//   console.log(v);
// });

// async function noob() {
//   return "noob";
// }

// noob().then((result) => {
//   console.log(result);
// }); // this is same as below but not explicitly

// function noob2() {
//   return Promise.resolve("noob2");
// }
// noob2().then((result) => {
//   console.log(result);
// }); // this is same as above but not explicitly

// function promiseFunction() {
//   return new Promise((resolve, reject) => {
//     setTimeout(() => {
//       resolve("i'm resolved now what next");
//     }, 1000);
//   });
// }
// // await keyword can only be used in async function, we cannot use await outside of async

// async function asyncFunction() {
//   console.log("waiting");
//   let a = await promiseFunction();
//   console.log(a);
// }
// asyncFunction();

// async function asyncFunction1() {
//   const promise = await new Promise((resolve, reject) => {
//     setTimeout(() => {
//       resolve("promise resolved after 2 seconds");
//     }, 2000);
//   });
//   console.log(promise);
//   const promise1 = await new Promise((resolve, reject) => {
//     setTimeout(() => {
//       resolve("promise1 resolved after 1 secondes but after first promise");
//     }, 1000);
//   });
//   console.log(promise1);
// }
// asyncFunction1();

// async function foo() {
//   const result1 = await new Promise((resolve) =>
//     setTimeout(() => resolve("1"))
//   );
//   console.log(result1);
//   const result2 = await new Promise((resolve) =>
//     setTimeout(() => resolve("2"))
//   );
//   console.log(result2);
// }
// foo();

// thenable object
// const myThenable = {
//   then: function (resolve, reject) {
//     setTimeout(() => resolve("Hello, world!"), 1000);
//   },
// };

// myThenable.then(
//   (value) => console.log(value), // This function will be called with 'Hello, world!' after 1 second
//   (error) => console.error(error) // This function will not be called
// );

// promise.resolve() && promise.reject()

// let n = Promise.resolve("foo");
// n.then((result) => {
//   console.log(result);
// }).catch((err) => {
//   console.log(err);
// });
// n.then((str) => {
//   console.log(str);
// return new Promise((resolve, reject) => {
//   setTimeout(() => {
//     str += "bar";
//     resolve(str);
//   }, 1000);
// }).then((str) => {
//   console.log(str);
// });
// .then((result) => {
//   console.log(result);
//   return new Promise((resolve, reject) => {
//     setTimeout(() => {
//       str += "baz";
//       resolve(str);
//     }, 2000);
//   });
// })
// .catch((err) => {
//   console.log(err);
// })
// .then((result) => {
//   console.log(result);
// })
// .catch((err) => {
//   console.log(err);
// });
// });
// TRY CATCH THROW CUSTOM ERRORS ERROR OBJECT

// function throwError() {
//   const message = document.getElementById("throwP");
//   message.innerHTML = "";
//   const values = document.getElementById("throw").value;

//   try {
//     if (values == "") throw "empty";
//     if (isNaN(values)) throw "not a number";
//     values = Number(values);
//     if (values < 10) throw "too high";
//     if (values > 10) throw "too low";
//   } catch (error) {
//     message.innerHTML = "input is " + error;
//   }
// }

// try {
//   x;
// } catch (error) {
// console.log(error.message, error.name, error.stack);
// console.log(error.name);
// console.log(error.message);
// console.log(error.stack);
// }

// try {
//   let x = prompt("enter your name ");
//   if (x !== "saad") throw ReferenceError`naah! liar! your name isn't ${x}`;
//   if (x == "saad") throw "good boy";
// } catch (error) {
//   console.log(error);
//   console.log(error.name);
//   console.log(error.message);
//   console.log(error.stack);
//   console.log("cause", { cause: error });
// }

// try {
//   let x = prompt("enter your name ");
//   if (x !== "saad")
//     throw new ReferenceError(`naah! liar! your name isn't ${x}`);
//   if (x == "saad") throw new Error("good boy");
//   // if (x == "jade venus") throw "you naughty naughty";
//   if (x == "aubrey kate") throw ReferenceError("you naughty naughty");
// } catch (error) {
//   console.log(error);
//   console.log(error.name);
//   console.log(error.message);
//   console.log(error.stack); // depreciated
//   console.log("cause", { cause: error });
// } finally {
//   console.log("huh!! finally done ");
// }

// try {
//   throw "I'm Evil";
//   console.log("You'll never reach to me", 123465);
// } catch (e) {
//   console.log(e); // I'm Evil
// }

// try {
//   throw new Error("I'm Evil");
//   console.log("You'll never reach to me", 123465);
// } catch (e) {
//   console.log(e.name, e.message); // Error I'm Evil
// }

// try {
//   throw Error("I'm Evil");
//   console.log("You'll never reach to me", 123465);
// } catch (e) {
//   console.log(e.name, e.message); // Error I'm Evil
// }

// console.log(typeof new Error("hello")); // object
// console.log(typeof Error); // function

// try {
//   try {
//     let x = 1;
//     if (x == 0) {
//       console.log("good");
//     } else {
//       throw new Error("fuck!");
//     }
//   } catch (error) {
//     console.log("inner catch", error);
//     throw new Error("oh fuck!");
//   }
// } catch (error) {
//   console.log("outer catch", error);
// }

// FETCH API

// let url = "https://jsonplaceholder.typicode.com/posts";
// fetch(url /* , options/args */)
//   .then((result) => {
//     console.log(result.headers);
//     console.log(result.status);
//     console.log(result.ok);
//     if (result.status !== 200 && result.ok == false) {
//       throw new Error("sorry internal server issuse ");
//     } else {
//       return result.json();
//     }
//   })
//   .then((result) => {
//     console.log(result);
//   })
//   .catch((err) => {
//     console.log(err);
//   });

// let url = " https://jsonplaceholder.typicode.com/posts";
// let data = { title: "foo", body: "bar", userId: 101 };

// fetch(url, {
//   method: "POST",
//   headers: {
//     "Content-type": "application/json; charset=UTF-8",
//   },
//   body: JSON.stringify(data),
// });
// .then((result) => {
//   return result.json();
// })
// .then((result) => {
//   console.log(result);
// });

// async function fetching(uri) {
//   let response = await fetch(uri);
//   let responseFormat = await response.json();
//   console.log(responseFormat);
// }
// fetching(url);

// (async () => {
//   let response = await fetch(url);
//   if (response.ok == false) {
//     throw new Error("couldn't fetch data from server");
//   } else {
//     let responseFormat = await response.json();
//     console.log(responseFormat);
//   }
// })(); // error handling for this function

fetch("https://jsonplaceholder.typicode.com/posts")
  .then((response) => {
    console.log(response);

    return response.json();
  })
  .then((data) => {
    console.log(data);
  });

// snake game by ChatGPT

// Set up the canvas and context
const canvas = document.getElementById("game");
const ctx = canvas.getContext("2d");

// Set up the snake and its initial position
const snake = [
  { x: 150, y: 150 },
  { x: 140, y: 150 },
  { x: 130, y: 150 },
];
const dx = 10;
const dy = 0;

// Set up the food and its initial position
let foodX = 300;
let foodY = 300;

// Set up the score
let score = 0;

// Set up the game loop
function gameLoop() {
  setTimeout(gameLoop, 100);

  // Move the snake
  const head = { x: snake[0].x + dx, y: snake[0].y + dy };
  snake.unshift(head);

  // Check if the snake has eaten the food
  if (snake[0].x === foodX && snake[0].y === foodY) {
    score++;
    // Generate a new piece of food
    foodX = Math.floor(Math.random() * 29) * 10;
    foodY = Math.floor(Math.random() * 29) * 10;
  } else {
    // Remove the tail of the snake if it hasn't eaten the food
    snake.pop();
  }

  // Clear the canvas
  ctx.clearRect(0, 0, canvas.width, canvas.height);

  // Draw the snake and the food
  snake.forEach((segment) => {
    ctx.fillStyle = "green";
    ctx.fillRect(segment.x, segment.y, 10, 10);
  });
  ctx.fillStyle = "red";
  ctx.fillRect(foodX, foodY, 10, 10);

  // Draw the score
  ctx.font = "20px Arial";
  ctx.fillText(`Score: ${score}`, 10, 20);
}

// Set up the keyboard controls
document.addEventListener("keydown", (event) => {
  if (event.key === "ArrowLeft") {
    dx = -10;
    dy = 0;
  } else if (event.key === "ArrowUp") {
    dx = 0;
    dy = -10;
  } else if (event.key === "ArrowRight") {
    dx = 10;
    dy = 0;
  } else if (event.key === "ArrowDown") {
    dx = 0;
    dy = 10;
  }
});

// Start the game loop
gameLoop();
