# DALia (Data Analysis LIbrAry)

DALia is going to be a C++ library meant for usage in various data analysis tasks - clustering and interference in 
particular. It shall be extended according to current needs.  

## Coding style

The base for coding style is included in such positions as:
* The Pragmatic Programmer: From Journeyman to Master - by Hunt and Thomas,
* Clean Code - by Uncle Bob,
* Code Complete - by McConnell.

It's meant to keep the functions and methods as short as it's possible, possibly let them have single resposibilities
and basically use good coding practices. 

### Naming conventions

There are several naming conventions that are meant to be used.

* Camel case should be used as default variables naming convention.

```
int variable = 0;
int otherVariable = 0;
```

* Class members names should start with underscore ('_').

```
class foo{
  public:
    int _bar = 0;
    long _fooBar = 0;
}
```

* Constants should be written using capitals, with underscores as word separators.

```
const double PI = 3.14;
const double PLANCKS_CONSTANT = 6.63e-34;
```

## Tabs

Preferred tab size is 2 spaces.

## Comments

Should be provided in Doxygen format.

## Brackets opening

Loosely according to The Pragmatic Programmer - all brackets should start at the end of line that requires them. E.g.

```
for(int i = 0; i < someValue; ++i){
  if(i == 0){
    // Some code.  
  }
  else{
    // Some other code.
  }
  // Lastly, the code.
}
```

It's ok to omit them if they're not required as in

```
  if(o.weight < 0) continue;
```

or

``` 
for(auto weight : weights)
  summaricWeight += weight;
```

## Maximal nesting level

Maximal nesting level is 3. Anything above that should be refactored. For example

```
while(true){
  for(int i = 0; i < someValue; ++i){
      
    if(someCondition){
      // Code.
    }
    else(
      // Other code.
    }
      
    for(auto value : values){
      // Some foreach code.
    }
  }
}
```

is ok, whereas

```
while(true){
  for(int i = 0; i < someValue; ++i){
      
    if(someCondition){
      for(auto value : values){
            // Some too highly nested foreach code.
          }
    }
    else(
      // Other code.
    }    
  }
}    
```

has one nesting level to much and should somehow be reduced. 
 

## Authors
* **Tomasz Rybotycki** - [Tomev](https://github.com/Tomev)

## License

This project is licensed under the GNU GPL v. 3 License - see the [LICENSE.md](LICENSE.md) file for details.

## Acknowledgments

* [Billie Thompson](https://github.com/PurpleBooth) for great readme.md template.
* [Andreas Renberg](https://github.com/IQAndreas) and contributors of [markdown-licenses] for md version of GNU GPL 3.

